cmake_minimum_required(VERSION 3.50)

project(HappyTowerControl)

file(GLOB_RECURSE SRC_FILES "src/*.cpp")

add_executable(${PROJECT_NAME}
main.cpp
${SRC_FILES}
)

set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE_DIR})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)