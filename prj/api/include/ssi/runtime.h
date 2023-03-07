






#define _runtime (ssi::runtime::instance())

namespace ssi
{
	class runtime
	{
		public:

		static runtime& instance()
		{
			//return ccl::singleton<runtime>::instance();
			return _rt;
		}

		const char* init() {
			return nullptr;
		}
		private:
			static runtime _rt;

	};




}