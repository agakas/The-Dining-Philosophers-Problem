#include "logger.h"
#include <thread>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>

Logger& Logger::instance() {
    static Logger logger;
    return logger;
}

void Logger::log(size_t philosopher_id, const std::string& action) {
    using namespace std::chrono;

    auto now = system_clock::now();
    auto ms = duration_cast<milliseconds>(now.time_since_epoch()) % 1000;

    std::time_t t = system_clock::to_time_t(now);
    std::tm tm = *std::localtime(&t);

    std::lock_guard<std::mutex> lock(mutex_);
    std::cout << "[TID " << std::this_thread::get_id() << "] "
              << "["
              << std::setw(2) << std::setfill('0') << tm.tm_hour << ":"
              << std::setw(2) << std::setfill('0') << tm.tm_min << ":"
              << std::setw(2) << std::setfill('0') << tm.tm_sec << ":"
              << std::setw(3) << std::setfill('0') << ms.count()
              << "] "
              << "Философ " << philosopher_id << " " << action
              << std::endl;
}