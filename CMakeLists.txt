# NOT WORKING SO FAR
# TO-DO
# Currently compiling with 
# g++ main.cpp ../include/SignalProcessor.cpp ../include/Identifier.cpp ../include/GuitarIdentifier.cpp ../include/DrumIdentifier.cpp ../include/FFTProcessor.cpp -o main
cmake_minimum_required(VERSION 3.10)

set(This AudioProcessor)

# Project name
project(${This} CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Add include directory for header files
include_directories(include)

# Enable testing
enable_testing()

# Add subdirectory for GoogleTest
add_subdirectory(googletest)

# Collect all header files
file(GLOB_RECURSE HEADERS
    include/*.h
)

# Collect all source files
file(GLOB_RECURSE SOURCES
    src/*.cpp
)

# Define the main executable
add_executable(${This} src/main.cpp)

# Add the library for shared source files (for testing)
add_library(AudioProcessorLib  STATIC ${SOURCES} ${HEADERS})

# Link libraries (if necessary)
# target_link_libraries(AudioProcessor <additional libraries, e.g., FFTW>)

# Link the executable with the library
target_link_libraries(AudioProcessor PRIVATE AudioProcessorLib)

# Add the test subdirectory
add_subdirectory(tests)
