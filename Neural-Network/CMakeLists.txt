cmake_minimum_required(VERSION 3.3)

file(GLOB_RECURSE MAIN_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
file(GLOB_RECURSE NEURALNETWORK_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE MODULES_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/modules/*.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/modules/*.h)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/vendor/modules)

add_executable(NeuralNetwork ${NEURALNETWORK_FILES} ${MAIN_FILES} ${MODULES_FILES})