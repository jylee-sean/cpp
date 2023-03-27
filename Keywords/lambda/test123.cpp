#include <iostream>

template<typename PreviousDispatcher, typename Msg, typename Func>
class TemplateDispatcher
{
  
  public:
  inline TemplateDispatcher()
  {
  }
  
  template<typename OtherMsg, typename OtherFunc>
  inline TemplateDispatcher<TemplateDispatcher<PreviousDispatcher, Msg, Func>, OtherMsg, OtherFunc> handle(OtherFunc && f)
  {
    return TemplateDispatcher<TemplateDispatcher<PreviousDispatcher, Msg, Func>, OtherMsg, OtherFunc>();
  }
};

/* First instantiated from: insights.cpp:40 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
class TemplateDispatcher<dispatcher, int, __lambda_40_22>
{
  
  public:
  inline TemplateDispatcher()
  {
  }
  
  template<typename OtherMsg, typename OtherFunc>
  inline TemplateDispatcher<TemplateDispatcher<dispatcher, int, (lambda)>, OtherMsg, OtherFunc> handle(OtherFunc && f);
  
  /* First instantiated from: insights.cpp:41 */
  #ifdef INSIGHTS_USE_TEMPLATE
  template<>
  inline TemplateDispatcher<TemplateDispatcher<dispatcher, int, __lambda_40_22>, double, __lambda_41_25> handle<double, __lambda_41_25>(__lambda_41_25 && f)
  {
    return TemplateDispatcher<TemplateDispatcher<dispatcher, int, __lambda_40_22>, double, __lambda_41_25>();
  }
  #endif
  
};

#endif
/* First instantiated from: insights.cpp:41 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
class TemplateDispatcher<TemplateDispatcher<dispatcher, int, __lambda_40_22>, double, __lambda_41_25>
{
  
  public:
  inline TemplateDispatcher()
  {
  }
  
  template<typename OtherMsg, typename OtherFunc>
  inline TemplateDispatcher<TemplateDispatcher<TemplateDispatcher<dispatcher, int, (lambda)>, double, (lambda)>, OtherMsg, OtherFunc> handle(OtherFunc && f);
  
  /* First instantiated from: insights.cpp:42 */
  #ifdef INSIGHTS_USE_TEMPLATE
  template<>
  inline TemplateDispatcher<TemplateDispatcher<TemplateDispatcher<dispatcher, int, __lambda_40_22>, double, __lambda_41_25>, char, __lambda_42_22> handle<char, __lambda_42_22>(__lambda_42_22 && f)
  {
    return TemplateDispatcher<TemplateDispatcher<TemplateDispatcher<dispatcher, int, __lambda_40_22>, double, __lambda_41_25>, char, __lambda_42_22>();
  }
  #endif
  
};

#endif
/* First instantiated from: insights.cpp:42 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
class TemplateDispatcher<TemplateDispatcher<TemplateDispatcher<dispatcher, int, __lambda_40_22>, double, __lambda_41_25>, char, __lambda_42_22>
{
  
  public:
  inline TemplateDispatcher()
  {
  }
  
  template<typename OtherMsg, typename OtherFunc>
  inline TemplateDispatcher<TemplateDispatcher<TemplateDispatcher<TemplateDispatcher<dispatcher, int, (lambda)>, double, (lambda)>, char, (lambda)>, OtherMsg, OtherFunc> handle(OtherFunc && f);
};

#endif


class dispatcher
{
  
  public:
  template<typename Message, typename Func>
  inline TemplateDispatcher<dispatcher, Message, Func> handle(Func && f)
  {
    return TemplateDispatcher<dispatcher, Message, Func>();
  }
  
  /* First instantiated from: insights.cpp:40 */
  #ifdef INSIGHTS_USE_TEMPLATE
  template<>
  inline TemplateDispatcher<dispatcher, int, __lambda_40_22> handle<int, __lambda_40_22>(__lambda_40_22 && f)
  {
    return TemplateDispatcher<dispatcher, int, __lambda_40_22>();
  }
  #endif
  
};




class receiver
{
  
  public:
  inline dispatcher wait()
  {
    return dispatcher();
  }
  
  // inline constexpr receiver() noexcept = default;
};




int main()
{
  receiver r = receiver();
      
  class __lambda_41_25
  {
    public:
    inline /*constexpr */ void operator()() const
    {
    }
    
    
  };
  
    
  class __lambda_40_22
  {
    public:
    inline /*constexpr */ void operator()() const
    {
    }
    
    
  };
  
  
  class __lambda_42_22
  {
    public:
    inline /*constexpr */ void operator()() const
    {
    }
    
    
  };
  
  r.wait().handle<int, __lambda_40_22>(__lambda_40_22{}).handle<double, __lambda_41_25>(__lambda_41_25{}).handle<char, __lambda_42_22>(__lambda_42_22{});
  return 0;
}

