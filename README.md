# kmercpp (WIP)

A 2bit representation of a k-mer using c++17 with a runtime implementation selector mechanism.

```cpp
#include <iostream>
#include <kmercpp/kmer.hpp>
#include <kmercpp/kmer_hash.hpp>
#include <kmercpp/loop_executor.hpp>

#define MAX_KMER_SIZE 512

template<size_t KSIZE>
struct EntryPoint
{
  using Type = kmercpp::Kmer<KSIZE>;
  void operator()(size_t kmer_size, int argc, char* argv[]) // use this as main
  {
    std::cerr << "Use K=" << kmer_size;
    std::cerr << " with " <<  Type::name() << " implementation." << std::endl;
  }
};

int main(int argc, char* argv[])
{
  std::string kmer_size(argv[1]);
  size_t ksize = std::stoll(kmer_size);

  // The first param ksize is for the selector, others are EntryPoint::operator() parameters.
  kmercpp::const_loop_executor<MAX_KMER_SIZE>::exec<EntryPoint>(ksize, ksize, argc, argv);
  return 0;
}
```

```
> g++ -std=c++17 -I./ main.cpp -o main
> main 30
Use K=30 with Kmer<32> - uint64_t implementation.
> main 50
Use K=50 with Kmer<64> - __uint128_t implementation.
> main 90
Use K=90 with Kmer<96> - uint64_t[3] implementation.
> main 115
Use K=115 with Kmer<128> - uint64_t[4] implementation.
> main 530 # throw, needs to increase MAX_KMER_SIZE -> #define MAX_KMER_SIZE 544
```