/*****************************************************************************
 *   kmercpp
 *   Authors: T. Lemane
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *****************************************************************************/

#pragma once
#include <cstddef>

#ifndef KMER_LIST
#define KMER_LIST 32, 64, 92, 128
#endif

#ifndef KMER_N
#define KMER_N 4
#endif

namespace kmercpp {

constexpr size_t kk[] = {KMER_LIST};

template<size_t start, size_t stop>
struct const_loop_executor
{
  template<template<size_t> typename Functor, typename... Args>
  static bool exec(size_t kmer_size, Args&&... args)
  {
    if (kmer_size <= kk[start])
    {
      Functor<kk[start]>()(std::forward<Args>(args)...);
      return true;
    }
    bool found = const_loop_executor<start + 1, stop>::template exec<Functor, Args...>(
      kmer_size, std::forward<Args>(args)...);
    if (!found)
      throw std::runtime_error("No implementation found for this k-mer size.");
    return true;
  }
};

template<size_t end>
struct const_loop_executor<end, end>
{
  template<template<size_t> typename Functor, typename... Args>
  static bool exec(size_t kmer_size, Args&&... args) { return false; }
};

};