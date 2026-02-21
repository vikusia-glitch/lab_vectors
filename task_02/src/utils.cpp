#include "utils.h"
#include <deque>
#include <benchmark/benchmark.h>

std::deque<int> generatedata(size_t n) {
    std::deque<int> deq;
    for (size_t i = 0; i < n; i++)
        deq.push_back(static_cast<int>(i));
    return deq;
}

void benchmark_pushback(benchmark::State& state) {
    auto N = state.range(0);
    std::deque<int> deq = generatedata(N);
    for (auto _ : state) {
        benchmark::DoNotOptimize(deq);
        deq.push_back(77);
        benchmark::ClobberMemory();
    }
    state.counters["size"] = static_cast<double>(deq.size());
}

void benchmark_pushfront(benchmark::State& state) {
    auto N = state.range(0);
    std::deque<int> deq = generatedata(N);
    for (auto _ : state) {
        benchmark::DoNotOptimize(deq);
        deq.push_front(77);
        benchmark::ClobberMemory();
    }
    state.counters["size"] = static_cast<double>(deq.size());
}

void benchmark_randominsert(benchmark::State& state) {
    auto N = state.range(0);
    std::deque<int> deq = generatedata(N);
    for (auto _ : state) {
        benchmark::DoNotOptimize(deq);
        deq.insert(deq.begin() + 9, 77);
        benchmark::ClobberMemory();
    }
    state.counters["size"] = static_cast<double>(deq.size());
}

void benchmark_randomerase(benchmark::State& state) {
    auto N = state.range(0);
    std::deque<int> deq = generatedata(N);
    for (auto _ : state) {
        if (deq.size() > 9) {
            benchmark::DoNotOptimize(deq);
            deq.erase(deq.begin() + 9);
            benchmark::ClobberMemory();
        }
    }
    state.counters["size"] = static_cast<double>(deq.size());
}

void benchmark_randomaccess(benchmark::State& state) {
    auto N = state.range(0);
    std::deque<int> deq = generatedata(N);
    for (auto _ : state) {
        if (deq.size() > 9) {
            benchmark::DoNotOptimize(deq[9]);
            deq[9] = 666;
            benchmark::ClobberMemory();
        }
    }
    state.counters["size"] = static_cast<double>(deq.size());
}

