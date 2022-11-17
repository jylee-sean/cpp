/**
 * g++ -std=c++14 -I /opt/homebrew/opt/boost/include state_machine.cc
*/
#define BOOST_TEST_MODULE Unit_test_example_04 
//#include <ccl/state_machine.h>
#include "state_machine.h"

//#define BOOST_TEST_DYN_LINK
#include <boost/test/included/unit_test.hpp>
#include <boost/test/tools/output_test_stream.hpp>
using boost::test_tools::output_test_stream;


struct state_msg{
    output_test_stream where; };
class robot_machine_A : public ccl::state_machine<robot_machine_A>{
    public:
    robot_machine_A(){
        transit(&robot_machine_A::start);
    }
    void run() override{
        (this->*state())();
        //state()(*this)();
    }
    void start(){
        once([&](){
            m.where << "start::once,";
        });
        transit(&robot_machine_A::standby,[&](){
            m.where << "start::transit,";
        });
    }
    void standby(){
        once([&](){
            m.where << "standby::once,";
        });
        transit(&robot_machine_A::terminate);
    }
    void terminate(){
        once([&](){
            m.where << "terminate::once,";
        });
        reenter(&robot_machine_A::start);
    } 
    state_msg m;
};

struct state_msg_B{
    int msg; };

class robot_machine_B : public ccl::state_machine<robot_machine_B, state_msg_B>{
    public:
    robot_machine_B(){
    }
    void run() override{
        transit(&robot_machine_B::start);
    }
    void run(state_msg_B m) {
        (this->*state())(m);
    }

    
    void start(state_msg_B m){
        state_t next;
        once([&](){
            m_t.where << "start::once,";
        });
        if(m.msg == 1){
            next = &robot_machine_B::start; }
        else{ 
            next = &robot_machine_B::standby; }
        transit(next,[&](){
            m_t.where << "start::transit,";
        });
    }
    void standby(state_msg_B m){
        once([&](){
            m_t.where << "standby::once,";
        });
        if(m.msg == 1)
            transit(&robot_machine_B::start);
        else if(m.msg == 2)
            reenter(&robot_machine_B::standby);
        
    } 
    state_msg m_t;
};
BOOST_AUTO_TEST_SUITE(CCL)




BOOST_AUTO_TEST_CASE(CASE0061) {
    /**
	 * @test{}
	 * @ref unit-test, @ref automated-test, @ref target-none
	 * @SRS{N/A}
	 * @SDS{N/A}
	 * @unit{ccl::state_machine}
	 * @description{
	 *		this test cases shows the way state machine works.
     *      prev() is invoked to check previous state.
     *      state() is invoked to check current state.
     *      run() is invoked to get the state change
     *      Also, internal method like transit, reetner, once are implemented in the templated class.
	 * }
	 * @prerequsite{
	 *		Remote QNX target is required
	 * }
	 * @environment{N/A}
	 * @parameters{
	 *		number of repetitions = 1
	 * }
	 * @instructions{N/A}
	 * @criteria{
	 *		PASS, if state transitions works successfully
	 *		FAIL, otherwise
	 * }
	 * @expect{
	 *		PASS
	 * }
	 * @result{
	 *		PASS / FAIL
	 * }
	 */

    robot_machine_A A;
    BOOST_TEST(!A.prev());
    BOOST_TEST(A.state() == &robot_machine_A::start);
    BOOST_TEST(A.m.where.is_empty());
    A.run();
    BOOST_TEST(A.prev() == &robot_machine_A::start);
    BOOST_TEST(A.state() == &robot_machine_A::standby);
    BOOST_TEST(A.m.where.is_equal("start::once,start::transit,"));
    A.run();
    BOOST_TEST(A.prev() == &robot_machine_A::standby);
    BOOST_TEST(A.state() == &robot_machine_A::terminate);
    BOOST_TEST(A.m.where.is_equal("standby::once,"));
    A.run();
    BOOST_TEST(!A.prev());
    BOOST_TEST(A.state() == &robot_machine_A::start);
    BOOST_TEST(A.m.where.is_equal("terminate::once,"));
}


BOOST_AUTO_TEST_CASE(CASE0062)
{
    /**
	 * @test{}
	 * @ref unit-test, @ref automated-test, @ref target-none
	 * @SRS{N/A}
	 * @SDS{N/A}
	 * @unit{ccl::state_machine}
	 * @description{
	 *		this test cases shows the way state machine works.
     *      prev() is invoked to check previous state.
     *      state() is invoked to check current state.
     *      run() is invoked to get the state change
     *      Also, internal method like transit, reetner, once are implemented in the templated class.
     *      In addition, msgs is given to the state machine during run()
	 * }
	 * @prerequsite{
	 *		Remote QNX target is required
	 * }
	 * @environment{N/A}
	 * @parameters{
	 *		number of repetitions = 1
	 * }
	 * @instructions{N/A}
	 * @criteria{
	 *		PASS, if state transitions works successfully
	 *		FAIL, otherwise
	 * }
	 * @expect{
	 *		PASS
	 * }
	 * @result{
	 *		PASS / FAIL
	 * }
	 */

    robot_machine_B B;
    BOOST_TEST(!B.prev());
    BOOST_TEST(!B.state());
    BOOST_TEST(B.m_t.where.is_empty());
    
    B.run();
    BOOST_TEST(!B.prev());
    BOOST_TEST(B.state() == &robot_machine_B::start);
    BOOST_TEST(B.m_t.where.is_empty());

    B.run(state_msg_B{1});
    BOOST_TEST(B.prev() == &robot_machine_B::start);
    BOOST_TEST(B.state() == &robot_machine_B::start);
    BOOST_TEST(B.m_t.where.is_equal("start::once,"));

    B.run(state_msg_B{0});
    BOOST_TEST(B.prev() == &robot_machine_B::start);
    BOOST_TEST(B.state() == &robot_machine_B::standby);
    BOOST_TEST(B.m_t.where.is_equal("start::transit,"));

    B.run(state_msg_B{0});
    BOOST_TEST(B.prev() == &robot_machine_B::start);
    BOOST_TEST(B.state() == &robot_machine_B::standby);
    BOOST_TEST(B.m_t.where.is_equal("standby::once,"));

    B.run(state_msg_B{2});
    BOOST_TEST(!B.prev());
    BOOST_TEST(B.state() == &robot_machine_B::standby);
    BOOST_TEST(B.m_t.where.is_equal("standby::once,"));

    B.run(state_msg_B{1});
    BOOST_TEST(B.prev() == &robot_machine_B::standby);
    BOOST_TEST(B.state() == &robot_machine_B::start);
    BOOST_TEST(B.m_t.where.is_equal("standby::once,"));
}



BOOST_AUTO_TEST_CASE(CASE0063)
{
    /**
	 * @test{}
	 * @ref unit-test, @ref automated-test, @ref target-none
	 * @SRS{N/A}
	 * @SDS{N/A}
	 * @unit{ccl::state_machine}
	 * @description{
	 *		this test cases shows the way state machine works.
     *      prev() is invoked to check previous state.
     *      state() is invoked to check current state.
     *      run() is invoked to get the state change
     *      Also, internal method like transit, reetner, once are implemented in the templated class.
     *      In addition, msgs is given to the state machine during run()
	 * }
	 * @prerequsite{
	 *		Remote QNX target is required
	 * }
	 * @environment{N/A}
	 * @parameters{
	 *		number of repetitions = 1
	 * }
	 * @instructions{N/A}
	 * @criteria{
	 *		PASS, if state transitions works successfully
	 *		FAIL, otherwise
	 * }
	 * @expect{
	 *		PASS
	 * }
	 * @result{
	 *		PASS / FAIL
	 * }
	 */

    robot_machine_B B;

    state_msg_B stB;

    stB.msg = 10;
    
    BOOST_TEST(!B.prev());
    BOOST_TEST(!B.state());
    BOOST_TEST(B.m_t.where.is_empty());
    
    B.run();
    BOOST_TEST(!B.prev());
    BOOST_TEST(B.state() == &robot_machine_B::start);
    BOOST_TEST(B.m_t.where.is_empty());

    B.run(state_msg_B{1});
    BOOST_TEST(B.prev() == &robot_machine_B::start);
    BOOST_TEST(B.state() == &robot_machine_B::start);
    BOOST_TEST(B.m_t.where.is_equal("start::once,"));

    B.run(state_msg_B{0});
    BOOST_TEST(B.prev() == &robot_machine_B::start);
    BOOST_TEST(B.state() == &robot_machine_B::standby);
    BOOST_TEST(B.m_t.where.is_equal("start::transit,"));

    B.run(state_msg_B{0});
    BOOST_TEST(B.prev() == &robot_machine_B::start);
    BOOST_TEST(B.state() == &robot_machine_B::standby);
    BOOST_TEST(B.m_t.where.is_equal("standby::once,"));

    B.run(state_msg_B{2});
    BOOST_TEST(!B.prev());
    BOOST_TEST(B.state() == &robot_machine_B::standby);
    BOOST_TEST(B.m_t.where.is_equal("standby::once,"));

    B.run(state_msg_B{1});
    BOOST_TEST(B.prev() == &robot_machine_B::standby);
    BOOST_TEST(B.state() == &robot_machine_B::start);
    BOOST_TEST(B.m_t.where.is_equal("standby::once,"));


    B.step(stB);
    BOOST_TEST(B.prev() == &robot_machine_B::start);
    BOOST_TEST(B.state() == &robot_machine_B::standby);

}

BOOST_AUTO_TEST_SUITE_END() // CCL