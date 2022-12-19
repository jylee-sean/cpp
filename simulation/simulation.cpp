#include <iostream>


class comst
{
    public:
        comst() {}
		enum map_t { in, out };
		static constexpr uint16_t invalid_slave_id = std::numeric_limits<uint16_t>::max();

        virtual ~comst(){}

};


class ecatmst : public comst
{
    public:
};

class env
{
    public:
};


template<typename T>
class coobj
{
    public:
        typedef T value_type;
        typedef uint16_t index_type;
        typedef uint8_t subindex_type;

		//explicit coobj(const index_type index = 0u, const subindex_type subindex = 0u, const flag_t flag = flag_t::rdwr, const mapping_t mapping = mapping_t::no, const T min = static_cast<T>(0), const T max = static_cast<T>(0), const T def = static_cast<T>(0)) :
		//	_mst(nullptr), _index(index), _subindex(subindex), _flag(flag), _mapping(mapping), _min(min), _max(max), _def(def) { }

		virtual ~coobj() { }
    
    protected:
        index_type _index;
        subindex_type _subindex;

        comst* _mst;

};

template<typename T>
class copdo : public coobj<T>
{

};

template<typename T>
class cosdo : public coobj<T>
{

};




namespace node
{
    class ds402
    {
        public:

        class StatusWord : public coobj<uint16_t>
        {
            public:
                StatusWord() : coobj<uint16_t>(0x6041u, 0x00u, rdonly, yes){}
                virtual ~StatusWord(){}
        };

        class ControlWord: public coobj<uint16_t>
        {
            public:
				ControlWord() : coobj<uint16_t>(0x6040u, 0x00u, rdwr, yes) { }
                virtual ~ControlWord() {}

        };

        class ProfileVelocity : public coobj<uint32_t>
        {
        public:
            ProfileVelocity() : coobj<uint32_t>(0x6081u, 0x00u, rdwr, yes) { }
            virtual ~ProfileVelocity() { }
        };

        class ProfileAcceleration : public coobj<uint32_t>
        {
        public:
            ProfileAcceleration() : coobj<uint32_t>(0x6083u, 0x00u, rdwr, yes) { }
            virtual ~ProfileAcceleration() { }
        };

        class ProfileDeceleration : public coobj<uint32_t>
        {
        public:
            ProfileDeceleration() : coobj<uint32_t>(0x6084u, 0x00u, rdwr, yes) { }
            virtual ~ProfileDeceleration() { }
        };

        class PositionActualValue : public coobj<int32_t>
        {
        public:
            PositionActualValue() : coobj<int32_t>(0x6064u, 0x00u, rdonly, yes) { }
            virtual ~PositionActualValue() { }
        };

        class VelocityActualValue : public coobj<int32_t>
        {
        public:
            VelocityActualValue() : coobj<int32_t>(0x606cu, 0x00u, rdonly, txmap) { }
            virtual ~VelocityActualValue() { }
        };

        class TargetPosition : public coobj<int32_t>
        {
        public:
            TargetPosition() : coobj<int32_t>(0x607au, 0x00u, rdwr, txrxmap) { }
            virtual ~TargetPosition() { }
        };
    };

    using elmo_obj = ds402;

    struct elmo_cfg
    {

    };

    class base
    {

        public:
            explicit base(comst& mst, const uint16_t id = comst::invalid_slave_id): _mst(mst), _id(id){}
            
            virtual ~base(){}

        protected:
            comst& _mst;
            uint16_t _id;
    };
    class elmo : public node::base
    {
        public:
            explicit elmo(comst& mst, const uint16_t id, comst elmo_cfg& cfg = node::elmo_cfg):
                base(mst, id), _cfg(cfg),
                _sdo
                {
                    cosdo<elmo_obj::StatusWord::value_type>(mst, id, elmo_obj::StatusWord()),
					cosdo<elmo_obj::ControlWord::value_type>(mst, id, elmo_obj::ControlWord()),
					cosdo<elmo_obj::ProfileVelocity::value_type>(mst, id, elmo_obj::ProfileVelocity()),
					cosdo<elmo_obj::ProfileAcceleration::value_type>(mst, id, elmo_obj::ProfileAcceleration()),
					cosdo<elmo_obj::ProfileDeceleration::value_type>(mst, id, elmo_obj::ProfileDeceleration())
                }{}
            virtual ~elmo(){}

                struct sdo_t
                {
                    cosdo<elmo_obj::StatusWord::value_type> statusWord;
				    cosdo<elmo_obj::ControlWord::value_type> controlWord;
          			cosdo<elmo_obj::ProfileVelocity::value_type> profileVelocity;
		    		cosdo<elmo_obj::ProfileAcceleration::value_type> profileAcceleration;
			    	cosdo<elmo_obj::ProfileDeceleration::value_type> profileDeceleration;
                };

            sdo_t& sdo() { return _sdo; }
            
            protected:
                sdo_t _sdo;
                const elmo_cfg _cfg;
    };
    class elmopp : public elmo
    {
        public:

            struct input_t
            {
                copdo<elmo_obj::StatusWord::value_type> statusWord;
                copdo<elmo_obj::PositionActualValue::value_type> positionActualValue;
                copdo<elmo_obj::VelocityActualValue::value_type> positionActualValue;
            };
            struct output_t
            {
				copdo<elmo_obj::ControlWord::value_type> controlWord;
				copdo<elmo_obj::TargetPosition::value_type> targetPosition;
            };
            elmopp() = delete;
            elmopp(comst& mst, const uint16_t id, const uint32_t input_addr, const uint32_t output_addr, const elmo_cfg& cfg):
                node::elmo::elmo(mst, id, cfg),
                _input
                {
                    copdo<elmo_obj::StatusWord::value_type>(mst, comst::in, input_addr +0x00u),
                    copdo<elmo_obj::PositionActualValue::value_type>(mst, comst::in, input_addr+0x10u),
                    copdo<elmo_obj::VelocityActualValue::value_type>(mst, comst::in, input_addr+0x30u)
                },
                _output
                {
                    copdo<elmo_obj::ControlWord::value_type>(mst, comst::out, output_addr + 0x00u),
					copdo<elmo_obj::TargetPosition::value_type>(mst, comst::out, output_addr + 0x10u)
                }
                {}
            virtual ~elmopp(){}

        private:
            input_t _input;
            output_t _output;
    };

}


class el1000
{
    public:
        el1000() = delete;
        explicit el1000(comst& m, env& e): _mst(m), _env(e){}

        virtual ~el1000(){};
        node::elmopp ltransl;
    
    private:
        env& _env;
        comst& _mst;

};

template<typename T>
class core
{
    public:
        core(T& t): _target(t){}

        void func(){
            _target.ltransl.sdo(); //.profileVelocity.write(_target.ltransl.convert(phy::units::millimeter(5.0)) );
        }
    private:
        T& _target;



};
int main()
{
    ecatmst emst;
    env e;
    el1000 target(emst, e);
    core<el1000> core_instance(target);

    // _target.ltransl.sdo().profileVelocity.write(_target.ltransl.convert(phy::units::millimeter(5.0)) );
	// _target.ltransl.sdo().profileAcceleration.write(_target.ltransl.convert(phy::units::millimeter(50.0)));
	// _target.ltransl.sdo().profileDeceleration.write(_target.ltransl.convert(phy::units::millimeter(50.0)));
	// _target.rtransl.sdo().profileVelocity.write(_target.rtransl.convert(phy::units::millimeter(5.0)) );
	// _target.rtransl.sdo().profileAcceleration.write(_target.rtransl.convert(phy::units::millimeter(50.0)));
	// _target.rtransl.sdo().profileDeceleration.write(_target.rtransl.convert(phy::units::millimeter(50.0)));



    return 0;
}