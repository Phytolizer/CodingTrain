cmake_minimum_required(VERSION 3.20)

project(
    CodingTrain
    LANGUAGES CXX
    VERSION 0.1.0
    DESCRIPTION "Coding Train Coding Challenges"
)

include("cmake/CPM.cmake")

CPMAddPackage(
    NAME SFML
    GITHUB_REPOSITORY SFML/SFML
    GIT_TAG 2.5.1
)

add_subdirectory("cpprocessing")
add_subdirectory("challenges")
