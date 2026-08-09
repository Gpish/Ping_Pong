#ifndef LOGGER
#define LOGGER

#include <stdio.h>
#include <string>
#include <iostream>
// #include <string_view>
#include <fstream>
#include <GLM/glm/gtx/io.hpp>

enum class LogLevel {
    DEBUG,
    INFO,
    WARN,
    ERROR
};

class Logger {
public:
    Logger();
    Logger(const std::string& logFile);
    ~Logger();

    template <typename... Args>
    void log(LogLevel level, const std::string& file, int line, Args&&... args) 
    {
        logStream << "[" << levelToString(level) << "]" << " [" << file << ":" << line << "] ";
        (logStream << ... << std::forward<Args>(args));
        logStream << "\n";
        logStream.flush();
    }

private:
    std::ofstream logStream;

    std::string_view levelToString(LogLevel level);
};

inline Logger logger("log.txt");

#define LOG_DEBUG(...) logger.log(LogLevel::DEBUG, __FILE__, __LINE__, __VA_ARGS__)
#define LOG_INFO(...) logger.log(LogLevel::INFO, __FILE__, __LINE__, __VA_ARGS__)
#define LOG_WARN(...) logger.log(LogLevel::WARN, __FILE__, __LINE__, __VA_ARGS__)
#define LOG_ERROR(...) logger.log(LogLevel::ERROR, __FILE__, __LINE__, __VA_ARGS__)

#endif