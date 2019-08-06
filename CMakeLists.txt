cmake_minimum_required (VERSION 3.15)

set(THIS_PROJECT libShortestPath)
project(${THIS_PROJECT})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)

enable_testing()

file(GLOB_RECURSE source_files "./src/*.cpp" "./src/*.h")

add_library(${THIS_PROJECT} STATIC ${source_files})
#add_executable(${THIS_PROJECT} ${source_files})

#Setup tests----
add_subdirectory(googletest)
set(TESTS_NAME libShortestPath_Tests)
file(GLOB_RECURSE test_files "./tests/*.cpp","./tests/*.hpp")
add_executable(${TESTS_NAME} ${test_files})
target_link_libraries(${TESTS_NAME} PUBLIC
    gtest_main
    ${THIS_PROJECT}
)
add_test(
    NAME ${TESTS_NAME}
    COMMAND ${TESTS_NAME}
)
#--------------