# NOT WORKING SO FAR
# TO-DO
# Currently compiling with 
# g++ main.cpp ../include/SignalProcessor.cpp ../include/Identifier.cpp ../include/GuitarIdentifier.cpp ../include/DrumIdentifier.cpp ../include/FFTProcessor.cpp -o main
cmake_minimum_required(VERSION 3.10)

# Project name
project(AudioProcessor_Mod)

set(CMAKE_C_STANDARD 99)
# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add source files
set(SOURCES
    src/main.cpp
    include/GuitarIdentifier.cpp
    include/FFTProcessor.cpp
)

# Include directories
include_directories(include/kissfft)

# Add executable
add_executable(main ${SOURCES})
