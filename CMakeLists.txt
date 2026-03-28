cmake_minimum_required(VERSION 3.10)

project(TreeLibrary)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create a library target (header-only)
add_library(tree_library INTERFACE)

target_include_directories(tree_library INTERFACE include)

# Example executable
add_executable(example examples/testing.cpp)

# Link library
target_link_libraries(example tree_library)
