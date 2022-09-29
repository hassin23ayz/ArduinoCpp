cmake_minimum_required(VERSION 3.1...3.24)

project(ObserverProj VERSION 0.1.0 LANGUAGES CXX)

add_library(ObserverLib Subject.cpp Subject.hpp Observer.hpp)

add_executable(ObserverRun main.cpp ClockTimer.cpp DigitalClock.cpp)

target_link_libraries(ObserverRun PRIVATE ObserverLib)
