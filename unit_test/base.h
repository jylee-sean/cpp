
class base : public ccl::event::observer<comst, comst::sync_done>
{
    public:


    base() = delete;

    explicit base(comst& mst, const uint16_t id = comst::invalid_slave_id) : 
        /*ccl::event::observer<comst, comst::sync_done>::observer(),*/ _mst(mst), _id(id)
        {std::cout<<"base constructor called"<<std::endl;}
    virtual ~base(){}
    virtual void update(comst& m, const comst::sync_done& e) override {}

    protected:
    comst& _mst;
    uint16_t _id;
    
};
