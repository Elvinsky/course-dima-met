cmake_minimum_required(VERSION 3.26)
project(course_dima_met_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(course_dima_met_1
        main.cpp
        src/medical_info_system/medical_info_system.cpp
        src/medical_info_system/medical_info_system.h
        src/user/user.cpp
        src/user/user.h
        src/medical_info_manipulator/medical_info_manipulator.cpp
        src/medical_info_manipulator/medical_info_manipulator.h
        src/creds_store/creds_store.cpp
        src/creds_store/creds_store.h)
