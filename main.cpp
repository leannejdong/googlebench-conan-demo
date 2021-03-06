#include <benchmark/benchmark.h>

//static void BM_StringCreation(benchmark::State& state) {
//  for (auto _ : state)
//    std::string empty_string;
//}
//// Register the function as a benchmark
//BENCHMARK(BM_StringCreation);
//
//// Define another benchmark
//static void BM_StringCopy(benchmark::State& state) {
//  std::string x = "hello";
//  for (auto _ : state)
//    std::string copy(x);
//}
//BENCHMARK(BM_StringCopy);
//
//BENCHMARK_MAIN();
static void BenchmarkTestOne(benchmark::State& state) {
    int Sum = 0;
    while (state.KeepRunning())
    {
        for (size_t i = 0; i < 100000; i++)
        {
            Sum += i;
        }
    }
}

static void BenchmarkTestTwo(benchmark::State& state) {
    int Sum = 0;
    while (state.KeepRunning())
    {
        for (size_t i = 0; i < 10000000; i++)
        {
            Sum += i;
        }
    }
}

static void BM_StringCompare(benchmark::State& state) {
  std::string s1(state.range(0), '-');
  std::string s2(state.range(0), '-');
  for (auto _ : state) {
    benchmark::DoNotOptimize(s1.compare(s2));
  }
  state.SetComplexityN(state.range(0));
}

// Register the function as a benchmark
BENCHMARK(BenchmarkTestOne);
BENCHMARK(BenchmarkTestTwo);
BENCHMARK(BM_StringCompare)->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity([](benchmark::IterationCount n)->double{return n; });

// Run the benchmark
BENCHMARK_MAIN();

/*
Google Benchmark tries to benchmark each candidate for a similar amount of time, and/or for long enough to get stable results.

The benchmark counts how many iterations it actually did, along with the exact time. A much slower per-iteration benchmark will do far fewer iterations.

The printout is (calculated) per-iteration time, and (counted) iterations of the benchmark function.

It might actually be a count of calls to state.KeepRunning().
*/
