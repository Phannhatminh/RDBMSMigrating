include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tests test_utils.cpp)
target_link_libraries(tests PRIVATE gtest_main mudop_utils)
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/include)
include(GoogleTest)
# Discover tests at test time to avoid issues when binaries aren't runnable at configure time
gtest_discover_tests(tests DISCOVERY_MODE PRE_TEST)

# Fallback: also register a single test that runs the binary (keeps CTest green if discovery fails)
add_test(NAME run_tests COMMAND $<TARGET_FILE:tests>)