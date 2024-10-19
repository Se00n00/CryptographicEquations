#CMake Version
cmake_minimum_required(VERSION 3.10)

#Project Version
project(CryptographicEquations VERSION 1.0)

#Specfy C Standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

#Header files Directory
include_directories(${PROJECT_SOURCE_DIR}/include)

#Add Executable Target
add_executable(Exe src/main.c)

