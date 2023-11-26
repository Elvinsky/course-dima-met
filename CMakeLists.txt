cmake_minimum_required(VERSION 3.26)
project(course_dima_met_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(course_dima_met_1
        main.cpp
        src/MedicalInfoSystem.cpp
        src/MedicalInfoSystem.h
        src/models/User.cpp
        src/models/User.h
        src/credsReader/creds_store.cpp
        src/credsReader/creds_store.h
        src/MedicalInfoManipulator/MedicakInfoManipulator.cpp
        src/MedicalInfoManipulator/MedicakInfoManipulator.h)
