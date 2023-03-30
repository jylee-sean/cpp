#include <iostream>
#include <string>
#include <vector>

// Abstract base class for loggers
class Logger {
public:
	virtual ~Logger() {}
    virtual void log(const std::string& message, int level) = 0;
};

// Console logger
class ConsoleLogger : public Logger {
public:
    void log(const std::string& message, int level) override {
        std::cout << "Console logger: " << message << " (level " << level << ")" << std::endl;
    }
};

// File logger
class FileLogger : public Logger {
public:
    FileLogger(const std::string& filename) : filename(filename) {}

    void log(const std::string& message, int level) override {
        std::cout << "File logger: " << message << " (level " << level << ") -> " << filename << std::endl;
        // write message to file here
    }

private:
    std::string filename;
};

// Email logger
class EmailLogger : public Logger {
public:
    EmailLogger(const std::string& email) : email(email) {}

    void log(const std::string& message, int level) override {
        std::cout << "Email logger: " << message << " (level " << level << ") -> " << email << std::endl;
        // send email here
    }

private:
    std::string email;
};

// Chain of responsibility class
class LoggerChain {
public:
    LoggerChain(Logger* logger) : logger(logger) {}

    void addLogger(Logger* newLogger) {
        if (nextLogger) {
            nextLogger->addLogger(newLogger);
        } else {
            nextLogger = new LoggerChain(newLogger);
        }
    }

    void log(const std::string& message, int level) {

        if (level <= logLevel) {
            logger->log(message, level);
        }
        if (nextLogger) {
            nextLogger->log(message, level);
        }
    }

    void setLogLevel(int level) {
        logLevel = level;
    }

private:
    Logger* logger;
    LoggerChain* nextLogger = nullptr;
    int logLevel = 0;
};

int main() {
	
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