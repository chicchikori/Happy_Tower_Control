cmake_minimum_required(VERSION 3.50)

project(HappyTowerControl)

include(FetchContent)


FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
)

FetchContent_Declare(
    nlohmann
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.12.0
)


FetchContent_MakeAvailable(SFML nlohmann)

file(GLOB_RECURSE SRC_FILES "src/*.cpp")

add_executable(${PROJECT_NAME}
main.cpp
${SRC_FILES}
)

set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE_DIR})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

target_link_libraries(${PROJECT_NAME} PUBLIC sfml-graphics sfml-window sfml-system nlohmann_json::nlohmann_json)

file(REMOVE_RECURSE ${CMAKE_BINARY_DIR}/Assets)
file(
    COPY ${CMAKE_SOURCE_DIR}/Assets
    DESTINATION ${CMAKE_BINARY_DIR}
)