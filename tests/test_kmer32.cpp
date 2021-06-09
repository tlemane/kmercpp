#include <gtest/gtest.h>
#define protected public
#include <kmercpp/kmer.hpp>
#include "test_utils.hpp"

#define K 32

using namespace kmercpp;

TEST(kmer32, kmer_ctr)
{
  Kmer<32> kmer; EXPECT_EQ(kmer.m_data, 0);
  for (size_t i=0; i<K; i++)
  {
    Kmer<32> skmer(i);
    EXPECT_EQ(skmer.m_data, 0);
    EXPECT_EQ(skmer.m_kmer_size, i);
  }
}

TEST(kmer32, kmer_set_data)
{
  Kmer<32> kmer(31);
  kmer.set64(42); EXPECT_EQ(kmer.m_data, 42);
  kmer.zero(); EXPECT_EQ(kmer.m_data, 0);
}

TEST(kmer32, kmer_set_str)
{
  for (size_t s=1; s<32; s++)
  {
    for (size_t i=0; i<1000; i++)
    {
      std::string kmer_str = random_dna_seq(s);
      Kmer<32> kmer(kmer_str);
      Kmer<32> kmer2; kmer2.set_polynom(kmer_str);
      Kmer<32> kmer3; kmer3.set_polynom(kmer_str.c_str(), kmer_str.size());
      EXPECT_EQ(kmer_str, kmer.to_string());
      EXPECT_EQ(kmer_str, kmer2.to_string());
      EXPECT_EQ(kmer_str, kmer3.to_string());
    }
  }
}

TEST(kmer32, kmer_get_data)
{
  Kmer<32> kmer; kmer.set64(0x0001020304050607);
  EXPECT_EQ(kmer.get64(), 0x0001020304050607);
  EXPECT_EQ(*kmer.get_data64(), 0x0001020304050607);
  EXPECT_EQ(kmer.get_data8()[0], 0x07);
  EXPECT_EQ(kmer.get_data8()[1], 0x06);
  EXPECT_EQ(kmer.get_data8()[2], 0x05);
  EXPECT_EQ(kmer.get_data8()[3], 0x04);
  EXPECT_EQ(kmer.get_data8()[4], 0x03);
  EXPECT_EQ(kmer.get_data8()[5], 0x02);
  EXPECT_EQ(kmer.get_data8()[6], 0x01);
  EXPECT_EQ(kmer.get_data8()[7], 0x00);
}


TEST(kmer32, kmer_access_data)
{

}

TEST(kmer32, kmer_comparison_operators)
{

}

TEST(kmer32, kmer_arithmetic_operators)
{

}

TEST(kmer32, kmer_bitwise_operators)
{

}

TEST(kmer32, kmer_assignment_operators)
{

}

TEST(kmer32, kmer_operations)
{

}

TEST(kmer32, kmer_str_representation)
{

}

TEST(kmer32, kmer_stream)
{

}



