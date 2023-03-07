

#include <iostream>
//https://stackoverflow.com/questions/55619550/rvalue-for-a-stdstring-parameter


std::string global_string;

void write_lvalue(std::string& str)
{

	global_string = str;

}


// only accept rvalue
void write_rvalue(std::string&& str)
{

	//global_string = str;
	global_string = std::move(str);

}

void write_lvalue_mut(std::string& text) {
    // move, no allocation... yay?
    global_string = std::move(text);
}


void
int main() {
    // equivalent, string created
    // and sent by reference (const& bind to temporaries)
    write_lvalue(std::string{"writing the Lvalue"}); 

    // equivalent, string created
    // and sent by reference (&& bind to temporaries)
    write_rvalue(std::string{"writing the Rvalue"});


	// write_lvalue("writing the Lvalue");
    // write_rvalue("writing the Rvalue");

    std::string s = /* ... */;
    write_lvalue_mut(std::move(s)); // fails
    write_lvalue_mut("some text"); // also fails

	return 0;
}