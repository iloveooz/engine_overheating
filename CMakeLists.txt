cmake_minimum_required(VERSION 3.12)
project(engine_overheating)

set(CMAKE_CXX_STANDARD 11)

add_executable(engine_overheating main.cpp environment.h engine.h entity.h)