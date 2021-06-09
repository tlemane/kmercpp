cmake_minimum_required(VERSION 3.10.0)
project(kmercpp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)

option(WITH_TESTS "Compile kmercpp tests." ON)

add_library(kmercpp INTERFACE)
target_include_directories(kmercpp INTERFACE ${CMAKE_SOURCE_DIR}/include)

if (WITH_TESTS)
  add_subdirectory(thirdparty)
  enable_testing()
  set(GTEST_INCLUDE ${THIRDPARTY_DIR}/googletest/googletest/include)
  set(GTEST_LIB ${THIRDPARTY_BUILD_DIR}/GTEST/src/GTEST-build/lib)
  add_subdirectory(tests)
endif(WITH_TESTS)

