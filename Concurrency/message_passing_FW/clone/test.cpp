
#include <iostream>
#include <memory>
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


class message_handler
{
public:
	explicit message_handler(std::shared_ptr<message_base> const& ref) : _ref(ref) { cout<<"first"<<endl;}
	~message_handler() { }

	//TODO:
	// i wanted to delete copy constructor because of its performance
	//message_handler(message_handler const& ref) { _ref = ref; cout<<"called"<<endl;}
   //	message_handler& operator=(message_handler const&) = delete;


   // message_handler(message_handler&& other): _ref(std::move(other._ref)){ }
//    message_handler(message_handler&& other): _ref(std::forward(other._ref)){ }

  message_handler(message_handler&& other): _ref(other._ref) {  cout<<"second"<<endl;}


	//message_handler(message_handler&& other): _ref(nullptr){}


	template<typename T, typename F>
	message_handler handle(F&& f) {
		if(wrapped_message<T>* wrapper = dynamic_cast<wrapped_message<T>*>(_ref.get()))
			f(wrapper->contents);
		return message_handler(_ref);
	}

private:
	std::shared_ptr<message_base> const& _ref;
};


class MyClass {
    int a, b;
 
public:
    MyClass(int i)
    {
		cout<<"constructor"<<endl;
        a = i;
        b = i;
    }
	
    // MyClass(const MyClass& c){
    //     cout<<"copy"<<endl;
    //     this->a = c.a;
    //     this->b = c.b;
    // }
    MyClass(const MyClass& c) = delete;

    MyClass(MyClass&& other){cout<<"??"<<endl;};

    void display()
    {
        std::cout << " a = " << a << " b = " << b << "\n";
    }
};

MyClass foo()
{

    return MyClass(1);
}

int main()
{

	// struct regulate { };
	// struct attached { };
	// struct detached { };
    // int a;
    
    // message_handler(std::make_shared<wrapped_message<attached>>(attached()))
    //                     .handle<regulate>([&](regulate const &msg){ cout<<"regulate!!"<<endl;} )
    //                     .handle<attached>([&](attached const &msg){ cout<<"attached!!"<<endl;});


    //MyClass a{1};
    //MyClass b = a;
    foo();


//    MyClass object(10);
//     object.display();
 
//     // Single parameter conversion constructor is invoked.
//     object = 20;
//     object.display();

}