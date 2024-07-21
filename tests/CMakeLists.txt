include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(
  unittest
  vec3_test.cpp
)

target_link_libraries(unittest lib)
target_link_libraries(
  unittest
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(unittest)
