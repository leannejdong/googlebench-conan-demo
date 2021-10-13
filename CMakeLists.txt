cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 20)

project(testgbench)

find_package(benchmark REQUIRED)

find_package(Threads REQUIRED)

function(add_benchmark NAME SOURCE)
  add_executable(${NAME} ${SOURCE})
  target_compile_features(${NAME} PRIVATE cxx_std_20)
  target_link_libraries(${NAME} PRIVATE benchmark::benchmark pthread)
endfunction()

# If conan is being used, configure CMake to use conan for dependencies.
include(${CMAKE_BINARY_DIR}/conan_paths.cmake OPTIONAL)

add_executable(main main.cpp)

target_link_libraries(main benchmark::benchmark Threads::Threads)

