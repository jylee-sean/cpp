/**
 * @brief		base class of single device based on CANopen
 * @details		all device nodes should inherit this class regardless of its communication base(EtherCAT, USB, or whatever)
 * @author		inode(joongyoung.eom@endoquestrobotics.com)
 * @version		initial
 * @copyright	EndoQuest Robotics, Inc. All rights reserved.
 */


#ifndef __SSI_NODE_BASE_H__
#define __SSI_NODE_BASE_H__

#include <cstdint>
#include <cstddef>

#include <string>

#include <ssi/copi.h>
#include <ssi/comst.h>

namespace ssi
{
	namespace node
	{
		class base : public ccl::event::observer<ssi::comst, ssi::comst::sync_done>
		{
		public:
			base() = delete;
			explicit base(comst& mst, const uint16_t id = comst::invalid_slave_id) :
				ccl::event::observer<ssi::comst, ssi::comst::sync_done>::observer(), _mst(mst), _id(id) { }

			virtual ~base() {}

			/**
			* additional initialization
			*/
			virtual const char* init() = 0;

			/**
			* additional fininalization
			*/
			virtual const char* fini() = 0;

			virtual void update(ssi::comst& m, const ssi::comst::sync_done& e) override { }

			comst& mst() { return _mst; }

			uint16_t id() { return _id; }

			std::string info() const { return std::string("slave #") + std::to_string(_id) + std::string(": "); }

		protected:
			/**
			* field bus master instance
			* all I/O of the ionode is executed by calling the master interfaces
			*/
			comst& _mst;

			/**
			* node's unique identifier on the field bus master
			* this value can be used as EtherCAT slave ID or something s/w dependent value like logical ID
			* remember that there is no way to detect id duplicated, so you can assign the value very carefully
			*/
			uint16_t _id;
		};
	}
}

#endif // __SSI_NODE_BASE_H__
