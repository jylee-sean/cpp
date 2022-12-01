namespace messaging
{
    template<typename PreviousDispatcher,typename Msg,typename Func>
    class TemplateDispatcher
    {
        queue* q;
        PreviousDispatcher* prev;
        Func f;
        bool chained;

        TemplateDispatcher(TemplateDispatcher const&)=delete;
        TemplateDispatcher& operator=(TemplateDispatcher const&)=delete;

        template<typename Dispatcher,typename OtherMsg,typename OtherFunc>
        friend class TemplateDispatcher;

        void wait_and_dispatch()
        {
			std::cout << "TemplateDispatcher::wait_and_dispatch()" << std::endl;
            for(;;)
            {
                auto msg=q->wait_and_pop();
                if(dispatch(msg)){
                    std::cout<<"dispatch!!"<<std::endl;   
                    break;
                }
            }
        }

        bool dispatch(std::shared_ptr<message_base> const& msg)
        {
			std::cout << "TemplateDispatcher::dispatch()" << std::endl;
            if(wrapped_message<Msg>* wrapper=
               dynamic_cast<wrapped_message<Msg>*>(msg.get()))
            {
                f(wrapper->contents);
                return true;
            }
            else
            {
                std::cout<<"prev dispatch!!"<<std::endl; 
                return prev->dispatch(msg);
            }
        }
    public:
        TemplateDispatcher(TemplateDispatcher&& other):
            q(other.q),prev(other.prev),f(std::move(other.f)),
            chained(other.chained)
        {
			std::cout << "TemplateDispatcher::TemplateDispatcher()" << std::endl;
            other.chained=true;
        }

        TemplateDispatcher(queue* q_,PreviousDispatcher* prev_,Func&& f_):
            q(q_),prev(prev_),f(std::forward<Func>(f_)),chained(false)
        {
			std::cout << "TemplateDispatcher::TemplateDispatcher(**&&)" << std::endl;
            prev_->chained=true;
        }

        template<typename OtherMsg,typename OtherFunc>
        TemplateDispatcher<TemplateDispatcher,OtherMsg,OtherFunc>
        handle(OtherFunc&& of)
        {
			std::cout << "TemplateDispatcher::handle()" << std::endl;
            return TemplateDispatcher<
                TemplateDispatcher,OtherMsg,OtherFunc>(
                    q,this,std::forward<OtherFunc>(of));
        }

        ~TemplateDispatcher() noexcept(false)
        {
			std::cout << "TemplateDispatcher::~TemplateDispatcher()" << std::endl;
            if(!chained)
            {
                wait_and_dispatch();
            }
        }
    };
}
