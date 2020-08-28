cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTestTemplateLinkedList TestLinkedListTemplate.cpp)
target_link_libraries(runTestTemplateLinkedList ${GTEST_LIBRARIES} pthread)
