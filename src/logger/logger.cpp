#include "logger.hpp"

Logger::Logger()
{
    this->logStream.open("../log.txt", std::ios::out | std::ios::trunc);

    if (!this->logStream.is_open()) {
        std::cerr << "Unable to open log file";
    }
}

Logger::Logger(const std::string& logFile)
{
    this->logStream.open(logFile, std::ios::out | std::ios::trunc);

    if (!this->logStream.is_open()) {
        std::cerr << "Unable to open log file";
    }
}


Logger::~Logger()
{
    if (this->logStream.is_open()) {
        this->logStream.close();
    }
}

std::string_view Logger::levelToString(LogLevel level)
{
    switch(level) {
        case LogLevel::INFO: return "INFO";
        case LogLevel::WARN: return "WARN";
        case LogLevel::DEBUG: return "DEBUG";
        case LogLevel::ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}
