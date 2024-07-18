cmake_minimum_required(VERSION 3.3)

project("NeuralNetwork" VERSION 1.0 LANGUAGES CXX)
add_subdirectory(Neural-Network)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT NeuralNetwork)