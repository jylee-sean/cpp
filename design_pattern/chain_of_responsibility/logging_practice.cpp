#include <iostream>
#include <string>
#include <vector>

class Logger
{
	public:
		virtual ~Logger(){}
		virtual void log(const std::string &str, int severity) = 0;
};

class FileLogger : public Logger
{
public:

	FileLogger(const std::string& f) : filename(f){
		
	}

	void log(const std::string &str, int severity) override{
		std::cout<<str << std::endl;

	}
private:
	std::string filename;
};
class ConsoleLogger : public Logger
{	
public:
	void log(const std::string &str, int severity) override{
		std::cout<<str << std::endl;

	}

private:

};

class EmailLogger : public Logger
{
public:
	EmailLogger(const std::string& adrs) : address(adrs){

	}

	void log(const std::string &str, int severity) override{
		std::cout<<str << std::endl;
	}
private:
	std::string address;
};
class LoggerChain
{

	public:
		LoggerChain(Logger* p): ptr(p){

		}
		void addLogger(Logger* logger){
			
			if(next){
				next->addLogger(logger);
			}else{
				next = new LoggerChain(logger);
			}


		}

		void setLogLevel(int lvl){
			logLevel = lvl;
		}

		void log(const std::string& str, int severity){

			if(logLevel <= severity)
				ptr->log(str, severity);

			if(next)
				next->log(str,severity);		
		}

	private:
		LoggerChain* next = nullptr;
		Logger* ptr = nullptr;
	    int	logLevel;
};


int main()
{


    // Create loggers
    Logger* consoleLogger = new ConsoleLogger();
    Logger* fileLogger = new FileLogger("log.txt");
    Logger* emailLogger = new EmailLogger("admin@example.com");

    // Create chain of responsibility
    LoggerChain chain(consoleLogger);
    chain.addLogger(fileLogger);
    chain.addLogger(emailLogger);

    // Set log level
    chain.setLogLevel(3);

    // Log messages
    chain.log("This is a debug message", 1);
    chain.log("This is an informational message", 2);
    chain.log("This is a warning message", 3);



	return 0;
}