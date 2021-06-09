#include <random>
#include <string>

inline std::string random_dna_seq(size_t size)
{
  static const char alpha[] = "ACGT";
  static std::default_random_engine g;
  static std::uniform_int_distribution<int> dist(0, 3);
  std::string seq;
  for (size_t i = 0; i < size; i++)
    seq.push_back(alpha[dist(g)]);
  return seq;
}