#pragma once
#include <string>
#include <mutex>

class Logger {
public:
    void log(size_t philosopher_id, const std::string& action);
    static Logger& instance();

private:
    Logger() = default;
    ~Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    std::mutex mutex_;  
};