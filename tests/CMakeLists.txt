cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Locate GTest
find_package(GTest REQUIRED)
include_directories(
    ${GTEST_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ../libs/csvfile/
    ../libs/csvfile/tests/
)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(
    runTests
    main_test.cpp
    ../addressbook.cpp
    ../libs/csvfile/csvfile.cpp
    ../libs/csvfile/common_utils.cpp
    ../libs/csvfile/convert_utf16.cpp
    ../libs/csvfile/tests/CsvFileTest.cpp

    addressbook_test.cpp
    ../libs/csvfile/tests/csvfile_test.cpp
)

target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
