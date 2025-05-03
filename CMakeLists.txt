cmake_minimum_required(VERSION 3.31)
project(HW11c)

set(CMAKE_CXX_STANDARD 20)

add_executable(HW11c main.cpp Passwords.txt
        Account.cpp
        Account.h
        Savings.cpp
        Savings.h
        Checkings.cpp
        Checkings.h)
