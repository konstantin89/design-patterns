#include <iostream>
#include <memory>
#include <string>
#include <chrono>
#include <iomanip> //std::put_time
#include <sstream>

// The Bridge design pattern (aka Handle, Body)
//
// The Bridge design pattern is a structural design pattern that is used 
// to separate an object's abstraction from its implementation. It does 
// so by creating two separate hierarchies: one for the abstraction and 
// another for the implementation. This separation allows both hierarchies 
// to evolve independently, making it easier to add new abstractions and 
// implementations without affecting existing code.

class LoggerBackend
{
public:
    virtual void ProcessLogLine(std::string line) = 0;
};

class UdpLoggerBackend : public LoggerBackend
{
public:
    void ProcessLogLine(std::string line) override
    {
        std::cout << "UDP logger: " << line << std::endl;
    }
};

class FileLoggerBackend : public LoggerBackend
{
public:
    void ProcessLogLine(std::string line) override
    {
        std::cout << "File logger: " << line << std::endl;
    }
};

class Logger
{
public:

    using LoggerBackendPtr = std::unique_ptr<LoggerBackend>;
    LoggerBackendPtr mLoggerBackend;

    Logger(LoggerBackendPtr& loggerBackend)
    {
        mLoggerBackend = std::move(loggerBackend);
    }

    void LogLine(std::string&& line)
    {
        mLoggerBackend->ProcessLogLine(line);
    }
};

int main()
{
    // We have different hierarchies for the logger and the logger backend.
    // We can add another logger backend (Console for example), but the Logger class
    // hierarchy will not be effected.

    std::unique_ptr<LoggerBackend> loggerBackEnd = std::make_unique<FileLoggerBackend>();
    Logger logger(loggerBackEnd);

    logger.LogLine("Hello World!");

    return 0;
}