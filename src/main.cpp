#include "table.h"
#include "philosopher.h"

#include <vector>
#include <thread>
#include <chrono>

int main() {
    const size_t philosophers_count = 5;

    Table table(philosophers_count);

    std::vector<Philosopher> philosophers;
    philosophers.reserve(philosophers_count);

    for (size_t i = 0; i < philosophers_count; ++i) {
        philosophers.emplace_back(i, table);
    }

    std::vector<std::thread> threads;
    threads.reserve(philosophers_count);

    for (size_t i = 0; i < philosophers_count; ++i) {
        threads.emplace_back(
            &Philosopher::dine,
            &philosophers[i]
        );
    }

    std::this_thread::sleep_for(std::chrono::seconds(5));

    table.stop();

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
