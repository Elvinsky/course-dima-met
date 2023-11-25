cmake_minimum_required(VERSION 3.26)
project(course_dima_met_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(course_dima_met_1
        main.cpp
        src/Controller.cpp
        src/Controller.h
        src/models/AbstractUser.cpp
        src/models/AbstractUser.h
        src/credsReader/CredsReader.cpp
        src/credsReader/CredsReader.h)
