cmake_minimum_required(VERSION 3.28)
project(log_output)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SRCS src/mlog/*.cpp)
include_directories(src/mlog/include)

add_library(mlog ${SRCS})
target_link_libraries(mlog Boost::uuid)
target_compile_options(mlog PRIVATE
-Wall -Wextra
-Wpedantic -Wshadow -Wconversion
)
target_compile_options(mlog PRIVATE $<$<CONFIG:Debug>:-D_GLIBCXX_DEBUG>)
set_target_properties(mlog PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/_)

add_executable(dlog src/main.cpp)
target_link_libraries(dlog mlog)
set_target_properties(dlog PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


include(FetchContent)
FetchContent_Declare(
    boost
    URL https://github.com/boostorg/boost/releases/download/boost-1.85.0/boost-1.85.0-cmake.zip
)
FetchContent_MakeAvailable(boost)