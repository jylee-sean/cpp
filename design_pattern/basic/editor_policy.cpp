#include <iostream>
#include <string>

class editor
{
	private:
		std::string data;
	public:
		void getData(){
			
			while(1){
				char c = getchar();
				
				if(c == '13')
					break;
			}
		}

};

int main()
{
	editor edit;

	edit.getData();

	return 0;
}

