#include <iostream>
#include <algorithm>
#include <tuple>
#include <array>


using namespace std;



namespace ssi
{
    namespace node
    {
        
        class elmo
        {
        public:
            
        };
        class elmopp
        {
        public:
            class profile
            {
                
            };
            
            class position_limits
            {
                
            };
        };
    }
    namespace target
    {
        // final ?
        class el1000 final
        {
        public:

            using elmo_tuple_t = std::tuple<node::elmo*, node::elmopp::profile, node::elmopp::position_limits>;
            

            // inline ?
            inline elmo_tuple_t& elmo(uint16_t slvid){ return elmotbl[slvid-1];}
            
            //inline node::elmo_ptr(uint16_t slvid){ return std::get<0>( elmo(slvid) ); }
            inline node::elmopp::profile& elmo_profile(uint16_t slvid) {return std::get<1>(elmo(slvid)); }
            inline node::elmopp::position_limits& elmo_position_limits(uint16_t slvid) {return std::get<2>(elmo(slvid)); }

            
        private:

            std::array<elmo_tuple_t, 4> elmotbl{
                std::make_tuple(nullptr, node::elmopp::profile(), node::elmopp::position_limits()),
                std::make_tuple(nullptr, node::elmopp::profile(), node::elmopp::position_limits()),
                std::make_tuple(nullptr, node::elmopp::profile(), node::elmopp::position_limits()),
                std::make_tuple(nullptr, node::elmopp::profile(), node::elmopp::position_limits())
            };
        };
    }
}

int main()
{
    //ssi::target::el1000 tgt;
	
    uint32_t data = 0xF123F987;
    
    //cout<<hex<< data & (1u<<7 | 1u <<4)<<endl;
    
    cout<<hex<< ( (data ^ (1u << 4)) & (1u << 4)  ) <<endl;
    cout<<hex<< ( (data ^ (1u << 7)) & (1u << 7)  )<<endl;
    //cout<<hex<< (3 & (1u<<0)) <<endl;
    return 0;
}
