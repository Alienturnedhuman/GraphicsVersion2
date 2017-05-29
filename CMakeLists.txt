cmake_minimum_required(VERSION 3.7)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES library.cpp library.h Element.cpp Element.h PhysicalModel.cpp PhysicalModel.h General.cpp General.h Entity.cpp Entity.h)
add_library(untitled ${SOURCE_FILES})