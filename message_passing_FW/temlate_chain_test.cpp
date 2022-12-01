#include <iostream>

template<typename PreviousDispatcher, typename Msg, typename Func>
class TemplateDispatcher
{
  
  public:
  TemplateDispatcher(){}
  template<typename OtherMsg, typename OtherFunc>
  TemplateDispatcher<TemplateDispatcher,OtherMsg,OtherFunc>handle(OtherFunc&& f){
      return TemplateDispatcher<TemplateDispatcher,OtherMsg,OtherFunc>();
  }
      
};

class dispatcher
{
  public:
  template<typename Message, typename Func>
  TemplateDispatcher<dispatcher,Message,Func> handle(Func&& f){
    return TemplateDispatcher<dispatcher,Message,Func>();
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
        .handle<int>([&]{})
        .handle<double>([&]{});


        // lambda 임시 객체 2개 생성
  
        return 0;
}
