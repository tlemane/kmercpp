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

namespace kmercpp {

template<size_t MAX_K, size_t SIZE = 32>
struct const_loop_executor
{
  template<template<size_t> typename Functor, typename... Args>
  static void exec(size_t kmer_size, Args&&... args)
  {
    if (kmer_size < SIZE)
    {
      Functor<SIZE>()(std::forward<Args>(args)...);
      return;
    }
    const_loop_executor<MAX_K, SIZE + 32>::template exec<Functor, Args...>(
      kmer_size, std::forward<Args>(args)...);
  }
};

template<size_t SIZE>
struct const_loop_executor<SIZE, SIZE>
{
  template<template<size_t> typename Functor, typename... Args>
  static void exec(size_t kmer_size, Args&&... args)
  {
    if (kmer_size < SIZE)
      Functor<SIZE>()(std::forward<Args>(args)...);
    else
      throw std::runtime_error("No implementation found for this k-mer size.");
  }
};

};