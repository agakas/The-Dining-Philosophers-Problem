#include "philosopher.h"
#include "table.h"
#include <thread>
#include <chrono>

Philosopher::Philosopher(size_t id, Table& table): id_(id), table_(table) {}

void Philosopher::think() {
    std::this_thread::sleep_for(
        std::chrono::milliseconds(100)
    );
}

void Philosopher::eat() {
    std::this_thread::sleep_for(
        std::chrono::milliseconds(100)
    );
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