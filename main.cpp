#include <iostream>
#include <kmercpp/kmer.hpp>
#include <kmercpp/kmer_hash.hpp>

#define KMER_LIST 32, 64, 92, 128
#define KMER_N 4

#include <kmercpp/loop_executor.hpp>

// program entry point, hash all k-mer from a string
template<size_t KSIZE>
struct EntryPoint
{
  using Type = kmercpp::Kmer<KSIZE>;
  using FollyHash = kmercpp::KmerHashers<0>::Hasher<KSIZE>;
  void operator()(size_t kmer_size, const std::string& seq)
  {
    FollyHash hasher;
    std::cerr << "Use K=" << kmer_size;
    std::cerr << " with " <<  Type::name() << " implementation." << std::endl;

    if (seq.size() < kmer_size)
      exit(EXIT_FAILURE);
  }
};

int main(int argc, char* argv[])
{
  std::string kmer_size(argv[1]);
  std::string seq = "";
  size_t ksize = std::stoll(kmer_size);

  // The first param ksize is for the selector, others are EntryPoint::operator() parameters.
  kmercpp::const_loop_executor<0, KMER_N>::exec<EntryPoint>(ksize, ksize, seq);
  return 0;
}