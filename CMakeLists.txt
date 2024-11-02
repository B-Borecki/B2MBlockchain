cmake_minimum_required(VERSION 3.10)

# In case of errors:
# set(CMAKE_CXX_COMPILER "Path/to/c++/compiler")
# set(CMAKE_C_COMPILER "Path/to/c/compiler")
# set(CMAKE_MAKE_PROGRAM "Path/to/make/program")
# set(Python_EXECUTABLE "Path/to/Python") 
# set(PYBIND11_PYTHON_VERSION PythonVersion)

project(B2MBlockchain)

add_subdirectory(extern/pybind11)

pybind11_add_module(main src/main.cpp)
