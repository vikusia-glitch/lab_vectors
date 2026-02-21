#include <benchmark/benchmark.h>
#include "utils.h"

int main() {
    benchmark::Initialize(nullptr, nullptr);
    for (auto N : {256, 512, 1024, 2048, 4096, 8192, 16384, 32768}) {
        benchmark::RegisterBenchmark("PushBack", benchmark_pushback)->Arg(N);
        benchmark::RegisterBenchmark("PushFront", benchmark_pushfront)->Arg(N);
        benchmark::RegisterBenchmark("RandomInsert", benchmark_randominsert)->Arg(N);
        benchmark::RegisterBenchmark("RandomErase", benchmark_randomerase)->Arg(N);
        benchmark::RegisterBenchmark("RandomAccess", benchmark_randomaccess)->Arg(N);
    }
    benchmark::RunSpecifiedBenchmarks();
    benchmark::Shutdown();//не обяз но пусть будет
    return 0;
}