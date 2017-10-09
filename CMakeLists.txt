cmake_minimum_required(VERSION 3.1)
project(TrainDetector)

add_definitions(-std=c++14)

set(SOURCE_FILES main.cpp)
add_executable(traindetector_run ${SOURCE_FILES})

include_directories(lib/traindetector)

add_subdirectory(lib/traindetector)
add_subdirectory(tests/traindetector_tests)

target_link_libraries(traindetector_run traindetector)