#pragma once

#include <cstddef>

class Table;

class Philosopher {
public:
    Philosopher(size_t id, Table& table);

    void dine();

private:
    void think();
    void eat();

    size_t id_;
    Table& table_;
};