cmake_minimum_required(VERSION 3.12)
project(engine_overheating VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

message("Сборка тестового задания")

set(company "Forward Development")
message(${company})

add_executable(engine_overheating main.cpp environment.h engine.h entity.h simulation.h)