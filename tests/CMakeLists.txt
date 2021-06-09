link_libraries(gtest gtest_main)

add_executable(kmer32-tests test_kmer32.cpp)
add_dependencies(kmer32-tests GTEST)
target_link_libraries(kmer32-tests PRIVATE kmercpp)
add_test(NAME kmer32 COMMAND sh -c "${PROJECT_BINARY_DIR}/tests/kmer32-tests")

add_executable(kmer64-tests test_kmer64.cpp)
add_dependencies(kmer64-tests GTEST)
target_link_libraries(kmer64-tests PRIVATE kmercpp)
add_test(NAME kmer64 COMMAND sh -c "${PROJECT_BINARY_DIR}/tests/kmer64-tests")

add_executable(kmer96-tests test_kmer96.cpp)
add_dependencies(kmer96-tests GTEST)
target_link_libraries(kmer96-tests PRIVATE kmercpp)
add_test(NAME kmer96 COMMAND sh -c "${PROJECT_BINARY_DIR}/tests/kmer96-tests")