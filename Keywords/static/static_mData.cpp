#include <iostream>
#include <memory>
#include <map>


class QObject
{
	public:
};

class IDataClient : public QObject
{
	public:
};
class Drape_Client : public IDataClient
{
	public:

	void func(){
		std::cout<<"func()"<<std::endl;
	}
};


class DataClient : public QObject
{
	public:
		std::shared_ptr<Drape_Client> m_drape = nullptr;
		bool initiateReplicas(){
			m_drape = std::make_shared<Drape_Client>();

			return true;
		}

		void logHandler(){
			m_logcounter++;
		}

		void call(){
			m_drape->func();
		}

		
	public:
		static int m_logcounter;

		std::map<DataClient*, int&> m{ this, &m_logcounter}
};

int DataClient::m_logcounter= 0;


int main()
{

	DataClient dc;
	dc.initiateReplicas();
	dc.logHandler();
	dc.call();
	return 0;
}