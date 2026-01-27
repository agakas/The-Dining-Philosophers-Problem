#pragma once

#include <vector>
#include <mutex>
#include <cstddef>
#include <condition_variable>

class Table {
public:
    Table(size_t count);

    void take_forks(size_t philosopher_id);
    void put_forks(size_t philosopher_id);

    //Для остановки
    void stop();
    bool stopped() const;

private:
    size_t count_;
    std::vector<bool> forks_;  //true - вилка свободна, иначе false
    std::mutex mutex_;
    std::condition_variable cv_;
    bool stop_ = false;     // Для остановки
};