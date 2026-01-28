#include "philosopher.h"
#include "table.h"
#include "logger.h"
#include <thread>
#include <chrono>

Philosopher::Philosopher(size_t id, Table& table): id_(id), table_(table) {}

void Philosopher::think() {
    Logger::instance().log(id_, "began to think");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    Logger::instance().log(id_, "finished thinking");
}

void Philosopher::eat() {
    Logger::instance().log(id_, "began to eat");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    Logger::instance().log(id_, "finished eating");
}

void Philosopher::dine() {
    while (!table_.stopped()) {
        think();

        table_.take_forks(id_);
        if (table_.stopped())
            break;

        eat();
        table_.put_forks(id_);
    }
}