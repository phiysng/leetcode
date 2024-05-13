cmake_minimum_required(VERSION 3.16)

project(leetcode-cpp)

set (CMAKE_CXX_STANDARD 17)

#force MSVC to use utf-8 encoding.
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
# enable /MP
add_compile_options($<$<CXX_COMPILER_ID:MSVC>:/MP>)

# not recommend by CMake! but it is acceptable in small project like this.
file(GLOB ALL_LEETCODE_CPP_FILES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/*.h" "${PROJECT_SOURCE_DIR}/*.cpp")

add_library(${PROJECT_NAME} ${ALL_LEETCODE_CPP_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC .)

add_executable(${PROJECT_NAME}-exe main.cpp)
target_link_libraries(${PROJECT_NAME}-exe PRIVATE ${PROJECT_NAME})