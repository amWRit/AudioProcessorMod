# Add GoogleTest
# find_package(GTest REQUIRED)
cmake_minimum_required(VERSION 3.10)

set(This AudioProcessorTests)

# add_subdirectory(${CMAKE_SOURCE_DIR}/googletest)

# Collect all test source files
file(GLOB_RECURSE TEST_SOURCES *.cpp)

# Test for AudioProcessor
add_executable(${This} ${TEST_SOURCES})

# Link GoogleTest libraries and the project's library
target_link_libraries(${This} PUBLIC
    gtest
    gtest_main
    pthread  # Required for GoogleTest
    AudioProcessorLib
)

# Enable tests to run with CTest
add_test(
    NAME ${This} 
    COMMAND ${This}
)
