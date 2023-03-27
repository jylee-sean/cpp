#include <iostream>

using namespace std;

template<typename PreviousDispatcher, typename Msg, typename Func>
class TemplateDispatcher
{
  
  public:
  TemplateDispatcher(){}
  template<typename OtherMsg, typename OtherFunc>
  TemplateDispatcher<TemplateDispatcher,OtherMsg,OtherFunc>handle(OtherFunc&& f){
      return TemplateDispatcher<TemplateDispatcher,OtherMsg,OtherFunc>();
  }

  ~TemplateDispatcher(){
	cout<<" dispatcher destroyed"<<endl;
  }

};

class dispatcher
{
  public:
  template<typename Message, typename Func>
  TemplateDispatcher<dispatcher,Message,Func> handle(Func&& f){
    return TemplateDispatcher<dispatcher,Message,Func>();
  }

  ~dispatcher(){
	cout<<" dispatcher destroyed"<<endl;
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


int main(void)
{
        receiver r;
        r.wait()
        .handle<int>([&]{"aaa";})
        .handle<double>([&]{"bbb";});


        
  
        return 0;
}
