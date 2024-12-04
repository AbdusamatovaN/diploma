cmake_minimum_required(VERSION 3.4...3.18)
project("CMakeProject1")

set(CMAKE_CXX_STANDARD 11)

# Find pybind11
find_package(pybind11 REQUIRED)

# Create the module
pybind11_add_module(sign_module bindings.cpp)