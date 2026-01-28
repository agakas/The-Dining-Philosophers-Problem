#include "table.h"
#include "logger.h"

Table::Table(size_t count) : count_(count), forks_(count, true) {}

void Table::take_forks(size_t id) {
    std::unique_lock<std::mutex> lock(mutex_);
    cv_.wait(lock, [&] { 
        return stop_ || (forks_[id] && forks_[(id + 1) % count_]);
    });

    if (stop_) return;

    forks_[id] = false;
    forks_[(id + 1) % count_] = false;

    Logger::instance().log(id, "took the forks");
}


void Table::put_forks(size_t id) {
    {
        std::lock_guard<std::mutex> lock(mutex_);
        forks_[id] = true;
        forks_[(id + 1) % count_] = true;
    }
    Logger::instance().log(id, "put down the forks");
    cv_.notify_all();
}

void Table::stop() {
    std::lock_guard<std::mutex> lock(mutex_);
    stop_ = true;
    cv_.notify_all();   // ← РАЗБУДИТЬ ВСЕХ
}

bool Table::stopped() const {
    return stop_;
}