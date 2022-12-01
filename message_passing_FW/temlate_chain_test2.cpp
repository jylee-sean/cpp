#include <iostream>

template<typename P, typename M, typename Func>
class K  
{
  
  public:
  K(){}
  template<typename B, typename C>
  K<K,B,C>handle(C&& f){
  	return K<K,B,C>();
  }
    
    
  
};

class D
{
  public:
  template<typename T, typename Func>
  K<D,T,Func> handle(Func&& f){
    return K<D,T,Func>();
  }
};


class A
{
	public:
  	D wait(){
    	return D();
    }
};


int main(void)
{
		A a;
  		a.wait()
        .handle<int>([&]{})
        .handle<double>([&]{});

        
  
        return 0;
}
