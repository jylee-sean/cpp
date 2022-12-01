
#include <iostream>

namespace ccl
{
	template<typename T, typename ...E>
	class state_machine
	{
	public:
		// typedef void (T::*state_t)();
		using state_t = void (T::*)(E...);
        

		state_machine() : _prev(nullptr), _curr(nullptr) { }

		virtual ~state_machine() { }

		state_machine(state_machine const&) = delete;

		state_machine& operator=(state_machine const&) = delete;

		virtual void run() = 0;

		inline void step(E... args) {

			//https://cppmagister.tistory.com/43 

    		

        	//] <<std::endl;
    		
			//std::cout<<"step called"<< ... << args <<std::endl;
			//if( (static_cast<T*>(this)->*state )== nullptr){
			//	std::cout<<"null ptr"<<std::endl;
			//}
			
			(static_cast<T*>(this)->*state())(args...);
			//((this)->*state())(args...);

		}
		
		inline const state_t prev() const {
			return this->_prev;
		}
		 
		inline const state_t state() const {
			return this->_curr;
		}

		inline bool inloop() const {
			return this->_prev == this->_curr;
		}

		inline bool inloop(state_t s) const {
			return inloop() && state() == s;
		}
		
	protected:
		state_t _prev;
		state_t _curr;

		template<typename F>
		inline void once(F&& f) {
			if(_prev != _curr)
				f();
		}

		inline void transit(state_t next) {
			this->_prev = this->_curr;
			this->_curr = next;
		}

		template<typename F>
		inline void transit(state_t next, F&& f) {
			if(next != _curr)
				f();
			transit(next);
		}

		inline void reenter(state_t next) {
			this->_prev = nullptr;
			this->_curr = next;
		}
	};
}