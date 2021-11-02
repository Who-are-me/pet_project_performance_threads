cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME cxx_thread_test)

project(${PROJECT_NAME} C CXX)

find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(THREADS_PREFER_PTHREAD_FLAG ON)
set(GCC_COVERAGE_COMPILE_FLAGS " -Ofast ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(${PROJECT_NAME}
        header/mdef
        src/main.cpp
        src/Function.cpp
        header/Function.hpp
        header/CalculatorIntegrals.hpp
        src/CalculatorIntegrals.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)
target_include_directories(${PROJECT_NAME} PUBLIC header)
target_include_directories(${PROJECT_NAME} PUBLIC src)

target_link_libraries( ${PROJECT_NAME} PRIVATE Threads::Threads)

