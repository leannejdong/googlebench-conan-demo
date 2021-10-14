cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 20)

project(testgbench)

#find_package(benchmark REQUIRED)

find_package(Threads REQUIRED)


# here conan is being used, configure CMake to use conan for dependencies.
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

add_executable(main main.cpp)

conan_basic_setup(TARGETS) # Introduce Conan-generated targets
add_compile_options(-std=c++2a -Wall -Wextra)
target_link_libraries(main CONAN_PKG::benchmark Threads::Threads)

#target_link_libraries(main benchmark::benchmark Threads::Threads)

