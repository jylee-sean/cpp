#include <iostream>
#include <memory>
#include <thread>
using namespace std;



struct message_base
{
    virtual ~message_base() { }
};

template<typename Msg>
struct wrapped_message : message_base
{
    Msg contents;
    explicit wrapped_message(Msg const& contents_) : contents(contents_) { }
};



template<typename PreviousDispatcher, typename Msg, typename Func>
class TemplateDispatcher
{
  
  private:
  PreviousDispatcher* _prev;
  Func _fn;

  public:
  TemplateDispatcher(){cout<<"this should not be pricted out"<<endl;}

  TemplateDispatcher(PreviousDispatcher* prev, Func&& f): _prev(prev),_fn(std::forward<Func>(f))
  {
    //cout<<"template dispatcher initialized "<<endl;
  }

  template<typename OtherMsg, typename OtherFunc>
  TemplateDispatcher<TemplateDispatcher,OtherMsg,OtherFunc>handle(OtherFunc&& f){


    //cout<<"message "<<typeid(Msg).name()<<endl;
    //cout<<"other message "<<typeid(OtherMsg).name()<<endl;
    //fn= f;
    return TemplateDispatcher<TemplateDispatcher,OtherMsg,OtherFunc>(this, std::forward<OtherFunc>(f));
  
  }


    void execute()
    {
      _fn();
    }
  
    ~TemplateDispatcher(){
    
    execute();
    //cout<<"destory TemplateDispatcher"<<endl;
  }

};

class dispatcher
{

 
  public:
  template<typename Message, typename Func>
  TemplateDispatcher<dispatcher,Message,Func> handle(Func&& f){


    //cout<<typeid(Message).name()<<endl;

    return TemplateDispatcher<dispatcher,Message,Func>(this,std::forward<Func>(f));
  }




  ~dispatcher(){
    //cout<<"destory disaptcher"<<endl;
  }
};


class receiver
{
    public:
    dispatcher wait()
    {
        return dispatcher();
    }
};



class message_handler
{
public:
  message_handler(std::shared_ptr<message_base> const& ref) : _ref(ref) { cout<<"basic constructed"<<endl; }
  ~message_handler() { }

  //TODO:
  // i wanted to delete copy constructor because of its performance
  message_handler(message_handler const&) = delete;
  message_handler& operator=(message_handler const&) = delete;

//        message_handler(message_handler&& other):_ref(std::move(other._ref)) {}
// message_handler(message_handler&& other) :_ref(other._ref)  {}

 message_handler(message_handler&& other) :_ref(nullptr)  { cout<<"move construct"<<endl; }
  template<typename T, typename F>
  message_handler handle(F&& f) {
    if(wrapped_message<T>* wrapper = dynamic_cast<wrapped_message<T>*>(_ref.get()))
      f(wrapper->contents);
    //return static_cast<message_handler&&>(message_handler(_ref));
    //
    return message_handler(_ref);
  }
private:
  std::shared_ptr<message_base> const& _ref;
};

namespace ctrl
{
  struct regulate { };
  struct attached { };
  struct detached { };
}







template<typename Func>
class Templaterecursive
{
  Func f;
  public:
  Templaterecursive(Templaterecursive const&)=delete;


  // template<typename OtherFunc>
  // friend class Templaterecursive;

  Templaterecursive(Func&& f_): f(std::forward<Func>(f_))
  {}

  Templaterecursive(Templaterecursive&& other): f(std::move(other.f))
  {
  }

  template<typename OtherFunc>
  Templaterecursive<OtherFunc> handle(OtherFunc&& of){
    return Templaterecursive<OtherFunc>(std::forward<OtherFunc>(of));
  }

};
class recursive
{
  public:
  recursive(){};
  recursive(recursive const&)=delete;


  template<typename Func>
  Templaterecursive<Func> handle(Func&& f){
    return Templaterecursive<Func>(std::forward<Func>(f));
  }
};

int main(void)
{


    bool flag = true;
    receiver r;
  
    std::thread t(
      [&]{
        while(flag){
        std::this_thread::sleep_for(1000ms);

        r.wait()
        .handle<int>([&]{cout<<"int"<<endl;})
        .handle<double>([&]{cout<<"double"<<endl;})
        .handle<char>([&]{cout<<"cahr"<<endl;});
        }
      }
    );

    int num;

    cout<<"main thread"<<endl;

    while(1)
    {
      cin>>num;
      switch(num){
        case 1:
          cout<<"send 1"<<endl;
          break;
        case 2:
          cout<<"send 2"<<endl;
          break;
        case 3: 
          cout<<"send 3 ----> quit"<<endl;
          flag = false;
          break;
      }

      if(!flag)
        break;
    }

    t.join();

	//messaging::message_handler(std::make_shared<messaging::wrapped_message<mymsg>>(mymsg(0x5678)))
		// .template handle<mymsg>([&](mymsg const& msg) {
		// 	BOOST_CHECK_EQUAL(msg.code, 0x5678);
		// })
		// .template handle<nomsg>([&](nomsg const& msg) {
		// 	BOOST_CHECK(false);
		// });
    //std::shared_ptr<messages_base> msg = std::make_shared<message_base>;


    // message_handler(std::make_shared<wrapped_message<ctrl::attached>>(ctrl::attached()))
    //                     .handle<ctrl::regulate>([&](ctrl::regulate const &msg){ cout<<"regulate!!"<<endl;})
    //                     .handle<ctrl::attached>([&](ctrl::attached const &msg){ cout<<"attached!!"<<endl;});

    // recursive r;
    // r.handle([&]{cout<<"first"<<endl;})
    //   .handle([&]{cout<<"second"<<endl;});


    return 0;
}
