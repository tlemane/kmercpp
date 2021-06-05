#include <iostream>
#include <kmercpp/kmer.hpp>
#include <kmercpp/kmer_hash.hpp>

#define KMER_LIST 32, 64, 96, 128
#define KMER_N 4

#include <kmercpp/loop_executor.hpp>

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
  kmercpp::const_loop_executor<0, KMER_N>::exec<EntryPoint>(ksize, ksize, argc, argv);
  return 0;
}