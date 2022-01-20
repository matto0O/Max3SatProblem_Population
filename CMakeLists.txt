cmake_minimum_required(VERSION 3.20)
project(TEPprojekt)

set(CMAKE_CXX_STANDARD 11)

add_executable(TEPprojekt main.cpp Clause.cpp Clause.h Max3SatProblem.cpp Max3SatProblem.h Individual.cpp Individual.h Optimizer.cpp Optimizer.h)
