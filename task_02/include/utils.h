#pragma once
#include <deque>
#include <benchmark/benchmark.h>

std::deque<int> generatedata(size_t n);

void benchmark_pushback(benchmark::State& state);
void benchmark_pushfront(benchmark::State& state);
void benchmark_randominsert(benchmark::State& state);
void benchmark_randomerase(benchmark::State& state);
void benchmark_randomaccess(benchmark::State& state);