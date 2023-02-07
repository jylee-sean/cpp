/**
 * @brief		hand control device class
 * @details		for now, only ForceDimension omega.6 and lambda.7(experimental) are capable for this class
 * @author		inode(joongyoung.eom@endoquestrobotics.com)
 * @version		initial
 * @copyright	EndoQuest Robotics, Inc. All rights reserved.
 */

#ifndef __CORE_HANDCTRL_H__
#define __CORE_HANDCTRL_H__

#include <unistd.h>
#include <pthread.h>

#include <dhdc.h>
#include <drdc.h>

#include <ccl/strategy.h>

#include <phy/types.h>
#include <phy/matrix.h>

#include <ssi/runtime.h>

#include <messaging/sender.h>
#include <messaging/receiver.h>
#include <messaging/message_base.h>

#include <error.h>
#include <messages.h>
#include <realtime.h>

namespace core
{
	class handctrl : public ccl::chain::handler<const realtime::tick>
	{
	public:
		// events to be sent to core state machine
		struct error { };

		enum type_t { left, right, all };

		static constexpr std::size_t narms = 2;
		static constexpr std::size_t naxes = 7;

		// tolerable diferrence of handctrl context
		//TODO: must be redefined with justification
		struct tolerance {
			static constexpr double position = 1.0;
			static constexpr double orientation = 0.1;
			static constexpr double gripper = 0.1;
		};

		class ctrl_base : public ccl::strategy<ctrl_base>
		{
		public:
			virtual ~ctrl_base() { }
			virtual bool init(const int rid) {
				/* if(!drdIsInitialized(rid)) */ (void)drdAutoInit(static_cast<char>(rid));
				(void)drdStart(static_cast<char>(rid));
				return true;
			}
			virtual bool fini(const int rid) {
				(void)drdRegulatePos(DHD_OFF, static_cast<char>(rid));
				(void)drdRegulateRot(DHD_OFF, static_cast<char>(rid));
				(void)drdRegulateGrip(DHD_OFF, static_cast<char>(rid));
				(void)drdStop(true, static_cast<char>(rid));
				return true;
			}

			virtual bool force(const int rid, const phy::pose_t f = { { 0.0, }, }) {
				drdSetForceAndTorqueAndGripperForce(f.pos(0), f.pos(1), f.pos(2), f.ori(0), f.ori(1), f.ori(2), f.grip, static_cast<char>(rid));
				return true;
			}

			virtual bool setForceOnHand(const int rid, const double coeff, double instlen) {
				double px, py, pz, f;

				dhdGetPosition(&px, &py, &py, static_cast<char>(rid));
				instlen /= 1000;			// mm -> m
				double x = px - instlen;
				f = -x * coeff;
				drdSetForceAndTorqueAndGripperForce(f, 0, 0, 
													0, 0, 0,
													0,
													static_cast<char>(rid));
				return true;
			}

			virtual bool regulate(const int rid, const bool pos_en, const bool rot_en, const bool grip_en) {
				(void)drdRegulatePos(pos_en, static_cast<char>(rid));
				(void)drdRegulateRot(rot_en, static_cast<char>(rid));
				(void)drdRegulateGrip(grip_en, static_cast<char>(rid));
				return true;
			}

			virtual bool moveto(const int rid, const phy::cartesian_t& pos, const bool sync = false) {
				return drdMoveToPos(pos(0), pos(1), pos(2), sync, static_cast<char>(rid)) == 0;
			}

			virtual bool orient(const int rid, const phy::euler_t& rot, const bool sync = false) {
				return drdMoveToRot(rot(0), rot(1), rot(2), sync, static_cast<char>(rid)) == 0;
			}

			virtual bool open(const int rid, const double& angle, const bool sync = false) {
				return drdMoveToGrip(angle, sync, static_cast<char>(rid)) == 0;
			}

			virtual bool ismoving(const int rid) {
				return drdIsMoving(static_cast<char>(rid));
			}

			virtual bool pos(const int hid, phy::pose_t* dst) const = 0;

			virtual void vibrate(const int rid, const bool sync = true) {
				double p[DHD_MAX_DOF]; 
				double r[3][3];
				char ID = static_cast<char>(rid);
				
				drdRegulatePos(true, ID);
				drdSetPosMoveParam(1, 1, 5000, ID);
				dhdGetPosition(&(p[0]), &(p[1]), &(p[2]), ID);

				// vibrate in y-axis
				drdMoveToPos(p[0], p[1] + 0.00025, p[2], sync, ID);
				drdMoveToPos(p[0], p[1] - 0.00025, p[2], sync, ID);

				drdSetPosMoveParam(1, 1, 1, ID);
				drdRegulatePos(false, ID);
			}

		private:
			std::mutex _lock;
		};

		class omega6 : public ctrl_base
		{
		public:
			virtual bool pos(const int hid, phy::pose_t* dst) const override {
				if(dst == nullptr || dhdGetPositionAndOrientationRad(&dst->pos(0), &dst->pos(1), &dst->pos(2), &dst->ori(0), &dst->ori(1), &dst->ori(2), static_cast<char>(hid)) == -1)
					return false;
				// convert meter to millimeter
				dst->pos(0) *= 1000;
				dst->pos(1) *= 1000;
				dst->pos(2) *= 1000;
				return true;
			}
		};

		class lambda7 : public ctrl_base
		{
		public:
			virtual bool pos(const int hid, phy::pose_t* dst) const override {
				if(dst == nullptr || dhdGetPositionAndOrientationRad(&dst->pos(0), &dst->pos(1), &dst->pos(2), &dst->ori(0), &dst->ori(1), &dst->ori(2), static_cast<char>(hid)) == -1)
					return false;
				if(dhdGetGripperAngleRad(&dst->grip, static_cast<char>(hid)) == -1)
					return false;
				// convert meter to millimeter
				dst->pos(0) *= 1000;
				dst->pos(1) *= 1000;
				dst->pos(2) *= 1000;
				return true;
			}
		};

		explicit handctrl(messaging::sender sender) : _sender(sender) { }

		virtual ~handctrl() { fini(); }

		const char* init(const int32_t priority = -1) {
			const char* what = nullptr;
			struct sched_param param;

			if(priority != -1) {
				/// temporarily boost this_thread's priority to change usbdi_event_handler's priority
				(void)sched_getparam(pthread_self(), &param);
				(void)pthread_setschedprio(pthread_self(), priority);
			}

			do {
				if(count() != 2) {
					what = "cannot find devices";
					break;
				}

				// trying to open omega.6 first
				_hid = { dhdOpenType(DHD_DEVICE_OMEGA33_LEFT), dhdOpenType(DHD_DEVICE_OMEGA33) };
				if(_hid[0] != -1 && _hid[1] != -1)
					_ctrl = _omega6();
				else {
					_hid = { dhdOpenType(DHD_DEVICE_LAMBDA331_LEFT), dhdOpenType(DHD_DEVICE_LAMBDA331) };
					_ctrl = _lambda7();
				}

				for(int i = 0; i < 2; i++) {
					_logd << "found a device { " << _hid[i] << ", " << dhdGetSystemType(_hid[i]) << ", " << dhdGetSystemName(_hid[i]) << " }";
					(void)dhdEnableForce(static_cast<unsigned char>(DHD_ON), static_cast<char>(_hid[i]));
				}

				if( (_hid[0] == -1) || (_hid[1] == -1) ) {
					what = "cannot open the handctrl device for haptic api";
					break;
				}

				_rid = { drdOpenID(static_cast<char>(_hid[0])), drdOpenID(static_cast<char>(_hid[1])) };

				if( (_rid[0] == -1) || (_rid[1] == -1) ) {
					what = "cannot open the handctrl device for robotics api";
					break;
				} else
					_logd << "rid has been assigned by { " << _rid[0] << ", " << _rid[1] << " }";

				std::lock_guard<std::mutex> lk(_lock);
				std::future<void> f[2];
				f[0] = std::async(std::launch::async, [&]{ if(_ctrl) _ctrl->init(0); });
				f[1] = std::async(std::launch::async, [&]{ if(_ctrl) _ctrl->init(1); });

				if(f[0].valid()) f[0].wait();
				if(f[1].valid()) f[1].wait();
			} while(false);

			/// restore this_thread's priority
			if(priority != -1)
				(void)pthread_setschedprio(0 /* this_thread */, param.sched_priority);

			if(what) {
				_loge << what;
				_ctrl = nullptr;
			}

			return what;
		}

		const char* fini() {
			const char* ret = nullptr;
			_ctrl = nullptr;
			for(int i = 0; i < 2; i++) {
				if(_ctrl) _ctrl->fini(static_cast<char>(i));
				(void)drdClose(static_cast<char>(_rid[i]));
				(void)dhdClose(static_cast<char>(_hid[i]));
			}
			return ret;
		}


		bool regulate(const bool pos_en, const bool rot_en, const bool grip_en, const type_t which = type_t::all) {
			if(!_ctrl) return false;
			if(which == type_t::left || which == type_t::all)
				_ctrl->regulate(0, pos_en, rot_en, grip_en);
			if(which == type_t::right || which == type_t::all)
				_ctrl->regulate(1, pos_en, rot_en, grip_en);
			return true;
		}

		bool open(const double* left, const double* right, const bool sync = true) {
			std::lock_guard<std::mutex> lk(_lock);
			std::future<void> f[2];
			if(left)
				f[0] = std::async(std::launch::async, [&]{
					pthread_setname_np(pthread_self(), "handctrl::open(0)");
					if(_ctrl) _ctrl->open(0, *left, sync);
				});

			if(right)
				f[1] = std::async(std::launch::async, [&]{
					pthread_setname_np(pthread_self(), "handctrl::open(1)");
					if(_ctrl) _ctrl->open(1, *right, sync);
				});

			if(f[0].valid()) f[0].wait();
			if(f[1].valid()) f[1].wait();

			return true;
		}

		bool orient(const phy::euler_t* left, const phy::euler_t* right, const bool sync = true) {
			std::lock_guard<std::mutex> lk(_lock);
			std::future<void> f[2];
			if(left)
				f[0] = std::async(std::launch::async, [&]{
					pthread_setname_np(pthread_self(), "handctrl::orient(0)");
					if(_ctrl) _ctrl->orient(0, *left, sync);
				});
			if(right)
				f[1] = std::async(std::launch::async, [&]{
					pthread_setname_np(pthread_self(), "handctrl::orient(1)");
					if(_ctrl) _ctrl->orient(1, *right, sync);
				});
			if(f[0].valid()) f[0].wait();
			if(f[1].valid()) f[1].wait();

			return true;
		}

		bool moveto(const phy::cartesian_t* left, const phy::cartesian_t* right, const bool sync = true) {
			std::lock_guard<std::mutex> lk(_lock);
			std::future<void> f[2];
			if(left)
				f[0] = std::async(std::launch::async, [&]{
					pthread_setname_np(pthread_self(), "handctrl::moveto(0)");
					if(_ctrl) _ctrl->moveto(0, *left, sync);
				});
			if(right)
				f[1] = std::async(std::launch::async, [&]{
					pthread_setname_np(pthread_self(), "handctrl::moveto(1)");
					if(_ctrl) _ctrl->moveto(1, *right, sync);
				});
			if(f[0].valid()) f[0].wait();
			if(f[1].valid()) f[1].wait();

			return true;
		}

		// for orientation and gripper
		bool tolerable(const phy::euler_t& o, const double g) {
			if( std::fabs(o(0)) <= tolerance::orientation &&
				std::fabs(o(1)) <= tolerance::orientation &&
				std::fabs(o(2)) <= tolerance::orientation &&
				std::fabs(g) <= tolerance::gripper )
				return true;
			return false;
		}

		void vibrate(const int rid, const bool sync = true){
			std::lock_guard<std::mutex> lk(_lock);
			std::future<void> f[2];
			if(rid == 0){
				f[0] = std::async(std::launch::async, [&]{
					pthread_setname_np(pthread_self(), "handctrl::vibrate(0)");
					if(_ctrl) _ctrl->vibrate(0, sync);
				});
			}
			if(rid == 1){
				f[1] = std::async(std::launch::async, [&]{
					pthread_setname_np(pthread_self(), "handctrl::vibrate(1)");
					if(_ctrl) _ctrl->vibrate(1, sync);
				});
			}
			if(f[0].valid()) f[0].wait();
			if(f[1].valid()) f[1].wait();
		}

		void setForceOnHand( const double linstLen, const double rinstLen, const double coeff = 200.0, const bool sync = false){
			std::lock_guard<std::mutex> lk(_lock);
			std::future<void> f[2];
			f[0] = std::async(std::launch::async, [&]{
					pthread_setname_np(pthread_self(), "handctrl::setForceOnHand(0)");
					if(_ctrl) _ctrl->setForceOnHand(0, coeff, linstLen);
			});
			f[1] = std::async(std::launch::async, [&]{
					pthread_setname_np(pthread_self(), "handctrl::setForceOnHand(1)");
					if(_ctrl) _ctrl->setForceOnHand(1, coeff, rinstLen);
			});
			if(f[0].valid()) f[0].wait();
			if(f[1].valid()) f[1].wait();
		}

		bool inRange(const int min, const int max){
			double p[DHD_MAX_DOF]; 
			dhdGetPosition(&(p[0]), &(p[1]), &(p[2]), static_cast<char>(0));
			dhdGetPosition(&(p[3]), &(p[4]), &(p[5]), static_cast<char>(1));
			
			for(int i = 0 ; i < 6 ; ++i){
				p[i] *= 1000;
				if(p[i] < min || p[i] > max) return false;
			}
			return true;
		}

		static int count() { return dhdGetDeviceCount(); }

		inline handctrl::ctrl_base& controller() {
			if(!_ctrl) throw ssi::instance_error("invalid ctrl_base");
			return *_ctrl;
		}

		inline const bool has_gripper(int hid) { return dhdHasGripper(static_cast<char>(hid)); }

		/**
		* this function retrives the gripper openning distance in meters
		* @param		hid is the device identifier for ForceDimension haptic API
		* @return		always gripper gap
		*/
		inline double gripper_gap(int hid) {
			double ret = 0.0;
			if(has_gripper(hid))
				(void)dhdGetGripperGap(&ret, static_cast<char>(hid));
			return ret;
		}

		inline int err() {
			return dhdErrorGetLast();
		}

		inline phy::pose_t pos(int id) {
			phy::pose_t ret;
			if(_ctrl == nullptr || !_ctrl->pos(id, &ret))
				_sender.raise(messaging::error(std::error_code(core::handctrl_api_error, core_category())));
			return ret;
		}

		inline phy::pose_t lpos() { return pos(0); }
		inline phy::pose_t rpos() { return pos(1); }

		inline int status(const unsigned int ind, int *stat)	
		{
			if(ind >= 2)
				throw ssi::invalid_argument("invalid argument for dhdGetStatus");

			return dhdGetStatus(stat,_hid[ind]);
		}

		void handle(const realtime::tick& e) override{
			static std::array<int,2> prev{0,0};

			int stat[2][DHD_MAX_STATUS];

			if(dhdGetStatus(stat[0],(_hid)[0]) == 0 && dhdGetStatus(stat[1],(_hid)[1]) == 0) {
				if(prev[0] != stat[0][DHD_STATUS_CONNECTED] || prev[1] != stat[1][DHD_STATUS_CONNECTED]){
					_logd << "left handctrl is " << static_cast<const char*>(stat[0][DHD_STATUS_CONNECTED] ? "connected" : "disconnected");
					_logd << "right handctrl is " << static_cast<const char*>(stat[1][DHD_STATUS_CONNECTED] ? "connected" : "disconnected");
					if(stat[0][DHD_STATUS_CONNECTED] && stat[1][DHD_STATUS_CONNECTED]){
						//It can't be reached though all device are connected until opened again.
						_sender.send(ssi::target::handctrl_connected());
					} else{
						_sender.raise(messaging::error(std::error_code(core::handctrl_disconnected, core_category())));
					}
				}
			} else // commented to prevent redundant error generation by inode
				; // _sender.raise(messaging::error(std::error_code(core::handctrl_status_error, core_category())));

			prev[0] = stat[0][DHD_STATUS_CONNECTED];
			prev[1] = stat[1][DHD_STATUS_CONNECTED];
		}

	private:
		std::array<int,2> _hid;
		std::array<int,2> _rid;

		ctrl_base* _ctrl = nullptr;

		std::mutex _lock;
		messaging::sender _sender;

		ctrl_base* _omega6() {
			static omega6 inst;
			return &inst;
		}

		ctrl_base* _lambda7() {
			static lambda7 inst;
			return &inst;
		}

	};
}


#endif // __CORE_HANDCTRL_H__