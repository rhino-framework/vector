cmake_minimum_required(VERSION 3.10)
project(vector LANGUAGES CXX)
set_property(TARGET PROPERTY CXX_STANDARD 17)

file(GLOB include "${PROJECT_SOURCE_DIR}/src/*.hpp")
file(GLOB source "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} ${include} ${source})
