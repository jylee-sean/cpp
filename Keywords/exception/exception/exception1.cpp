// to see exception throwing operation
#include <iostream>
#include <map>
enum class core_errc {
	success = 0,	// error condition on success 
	emergency,		// emergency
	recoverable,	// recoverable error
	unrecoverable,	// unrecoverable error
	other
};

//  std::error_code(core::emo_pressed, core_category())
namespace messaging
{
	struct error{
		error(const std::error_code& e) : _error_code(e){std::cout<<"error class constructed"<<std::endl;}
		const std::error_code error_code(
		) const { std::cout<<"error_code function called"<<std::endl; return _error_code; }
		private:
			std::error_code _error_code;
	};
};


namespace core {
	/**
	 * core error code
	 */
	enum error_t {
		success = 0x0000,
		epo_pressed = 0x2000,
		emo_pressed = 0x2001,
		boot_fail = 0x4001,
		connect_fail = 0x4002,
		restore_fail = 0x4003,
		instrument_detached = 0x4101,
		cart_stabil_uninstalled = 0x4103,
		console_stabil_uninstalled = 0x4104,
		fieldbus_error = 0x8000,
		topology_error = 0x8001,
		selftest_fail = 0x8002,
		elmo_enable_fail = 0x8010,
		elmo_init_fail = 0x8011,
		elmo_fault = 0x8012,
		gui_init_fail = 0x8020,
		gui_disconnected = 0x8021,
		handctrl_disconnected = 0x8030,
		handctrl_status_error = 0x8031,
		handctrl_api_error = 0x8032,
		vscope_detached = 0x8110,
		edrive_detached = 0x8111,
		left_drape_detached = 0x8120,
		right_drape_detached = 0x8121,
		vscope_drape_detached = 0x8122,
		edrive_drape_detached = 0x8123,
		edrive_clutch_disengaged = 0x8130,
		internal_error = 0x8fff
	};
}

namespace std {
	template<> struct is_error_condition_enum<core_errc> : public true_type { };
}

class core_category_t : public std::error_category {
public:
	virtual const char* name() const noexcept override { return "core_error"; }

	virtual std::error_condition default_error_condition(int code) const noexcept override {
		if(code >= 0x0000 && code < 0x2000) return std::error_condition(core_errc::success);
		else if(code >= 0x2000 && code < 0x4000) return std::error_condition(core_errc::emergency);
		else if(code >= 0x4000 && code < 0x8000) return std::error_condition(core_errc::recoverable);
		else if(code >= 0x8000 && code < 0xc000) return std::error_condition(core_errc::unrecoverable);
		else return std::error_condition(core_errc::other);
	}

	virtual bool equivalent(const std::error_code& code, int condition) const noexcept override {
		return *this == code.category() && static_cast<int>(default_error_condition(code.value()).value()) == condition;
	}

	virtual std::string message(int code) const override {
		return std::get<0>(_map.at(code));
	}

	std::string notice(int code) const {
		return std::get<1>(_map.at(code));
	}

private:
	const std::map<int, std::tuple<std::string, std::string>> _map = {
		{ core::success, { "success", "null" } },
		{ core::epo_pressed, { "EPO button is pressed", "try to recover system" } },
		{ core::emo_pressed, { "EMO button is pressed", "try to recover system" } },
		{ core::boot_fail, { "boot fail", "reset the subsystems" } },
		{ core::connect_fail, { "connect fail", "check if the system cable is connected" } },
		{ core::restore_fail, { "restore fail", "check if all drape adapters and colubriscope are attached" } },
		{ core::instrument_detached, { "instrument detached", "check if instruments are attached" } },
		{ core::cart_stabil_uninstalled, { "cart stabilizer is not installed", "check if the cart stabilizer is installed properly" } },
		{ core::console_stabil_uninstalled, { "console stabilizer is not installed", "check if the console stabilizer is installed properly" } },
		{ core::fieldbus_error, { "ecat bus is unstable", "N/A" } },
		{ core::topology_error, { "ecat topology error", "check the field-bus connection"} },
		{ core::selftest_fail, { "selftest fail", "check if the joints are physically damaged or blocked" } },
		{ core::elmo_enable_fail, { "elmo enable fail", "try to recover" } },
		{ core::elmo_init_fail, { "elmo init fail", "try to recover" } },
		{ core::elmo_fault, { "elmo fault", "try to recover" } },
		{ core::gui_init_fail, { "gui init fail", "N/A" } },
		{ core::gui_disconnected, { "gui disconnected", "check if Ethernet connection to JUPITER" } },
		{ core::handctrl_disconnected, { "handctrl disconnected", "check if the handctrl is connected" } },
		{ core::handctrl_status_error, { "handctrl status error", "N/A" } },
		{ core::handctrl_api_error, { "handctrl api error", "N/A" } },
		{ core::vscope_detached, { "videoscope is detached", "N/A" } },
		{ core::edrive_detached, { "colubriscope is detached", "N/A" } },
		{ core::left_drape_detached, { "left drape is detached", "N/A" } },
		{ core::right_drape_detached, { "right drape is detached", "N/A" } },
		{ core::vscope_drape_detached, { "vscope drape is detached", "N/A" } },
		{ core::edrive_drape_detached, { "edrive drape is detached", "N/A" } },
		{ core::edrive_clutch_disengaged, { "edrive clutch is disengaged", "N/A" } },
		{ core::internal_error, { "internal error", "N/A" } }
	};
};

// return singleton instance
const std::error_category& core_category() noexcept {
	static core_category_t _category;
	return _category;
}

std::error_condition make_error_condition(core_errc e) {
	return std::error_condition(static_cast<int>(e), core_category());
}

// if(dynamic_cast<wrapped_message<messaging::error>*>(msg.get())) {
// 	throw messaging::error(dynamic_cast<wrapped_message<messaging::error>*>(msg.get())->contents);
// }

void func(int value)
{
	std::cout<< value <<std::endl;
	if( value  == 5){
		std::cout<<"excetpion throwing"<<std::endl;
		throw messaging::error(std::error_code(core::emo_pressed, core_category()));
		
		//throw std::runtime_error("runtime error");
	}

}
int main()
{

	int n=10;
	while(n--)
	{

		try{
			func(n);
		}
		
		catch(messaging::error const &e){
			std::cout<<"catch"<<std::endl;
			n = 0;
		}

	}
	
	return 0;
}