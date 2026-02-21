#include "utils.h"
#include <vector>
#include <benchmark/benchmark.h>

#include "utils.h"
#include <vector>
#include <benchmark/benchmark.h>

std::vector<int> generatedata(size_t n) {
    std::vector<int> vect(n);
    for (size_t i = 0; i < n; ++i)
        vect[i] = static_cast<int>(i);
    return vect;
}
void benchmark_pushback(benchmark::State& state) {
    auto N = state.range(0);

    std::vector<int> vect = generatedata(N);
    vect.reserve(N + 1);

    for (auto _ : state) {
        benchmark::DoNotOptimize(vect.data());
        vect.push_back(77);
        benchmark::ClobberMemory();
        vect.pop_back();
    }

    state.counters["size"] = static_cast<double>(vect.size());
    state.counters["capacity"] = static_cast<double>(vect.capacity());
}

void benchmark_pushfront(benchmark::State& state) {
    auto N = state.range(0);

    std::vector<int> vec = generatedata(N);
    vec.reserve(N + 1);

    for (auto _ : state) {
        benchmark::DoNotOptimize(vec.data());
        vec.insert(vec.begin(), 77);
        benchmark::ClobberMemory();
        vec.erase(vec.begin());
    }

    state.counters["size"] = static_cast<double>(vec.size());
    state.counters["capacity"] = static_cast<double>(vec.capacity());
}

void benchmark_randominsert(benchmark::State& state) {
    auto N = state.range(0);

    std::vector<int> vect = generatedata(N);
    vect.reserve(N + 1);

    for (auto _ : state) {
        benchmark::DoNotOptimize(vect.data());
        vect.insert(vect.begin() + 9, 77);
        benchmark::ClobberMemory();
        vect.erase(vect.begin() + 9);
    }

    state.counters["size"] = static_cast<double>(vect.size());
    state.counters["capacity"] = static_cast<double>(vect.capacity());
}

void benchmark_randomerase(benchmark::State& state) {
    auto N = state.range(0);

    std::vector<int> vect = generatedata(N);

    for (auto _ : state) {
        benchmark::DoNotOptimize(vect.data());
        vect.erase(vect.begin() + 9);
        benchmark::ClobberMemory();
        vect.insert(vect.begin() + 9, 9);
    }

    state.counters["size"] = static_cast<double>(vect.size());
    state.counters["capacity"] = static_cast<double>(vect.capacity());
}

void benchmark_randomaccess(benchmark::State& state) {
    auto N = state.range(0);

    std::vector<int> vec = generatedata(N);

    for (auto _ : state) {
        benchmark::DoNotOptimize(vec[9]);
        vec[9] = 666;
        benchmark::ClobberMemory();
    }

    state.counters["size"] = static_cast<double>(vec.size());
    state.counters["capacity"] = static_cast<double>(vec.capacity());
}