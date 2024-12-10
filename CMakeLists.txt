# NOT WORKING SO FAR
# TO-DO
# Currently compiling with 
# g++ main.cpp ../include/SignalProcessor.cpp ../include/Identifier.cpp ../include/GuitarIdentifier.cpp ../include/DrumIdentifier.cpp ../include/FFTProcessor.cpp -o main -I kissfft ../include/kissfft/kiss_fft.c

cmake_minimum_required(VERSION 3.10)

# Project name
project(GuitarAudioProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Add source files
set(SOURCES
    src/main.cpp
    include/GuitarIdentifier.cpp
    include/FFTProcessor.cpp
    include/kissfft/kiss_fft.c
)

# Include directories
include_directories(include/kissfft)

# Add executable
add_executable(main ${SOURCES})
