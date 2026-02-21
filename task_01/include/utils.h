#pragma once
#include <vector>
#include <benchmark/benchmark.h>

std::vector<int> generatedata(size_t n);
void benchmark_pushback(benchmark::State& stat);
void benchmark_pushfront(benchmark::State& stat);
void benchmark_randominsert(benchmark::State& stat);
void benchmark_randomerase(benchmark::State& stat);
void benchmark_randomaccess(benchmark::State& stat);


