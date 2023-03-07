
cmake_minimum_required (VERSION 3.6.3)

project(mytestsuite)

enable_language(C)
enable_language(CXX)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# set(BOOST_DIR /opt/homebrew/opt/boost)
# set(BOOST_TAG boost-1.81.0)


#need to include __config to compile boost with QNX SDP 7.0 and 7.1
#include_directories(${CMAKE_SOURCE_DIR}/patches)

include_directories(/opt/homebrew/opt/boost/include)
link_directories(/opt/homebrew/opt/boost/lib)
# include_directories(../ccl/include/ccl)

#add_library(libTestcase STATIC testcase.cc)
add_library(libTestcase SHARED testcase.cc)
#add_dependencies(CCLChain stage_ccl)

#set(SRC_FILES main.cpp)


add_executable(mytest.test test2.cpp)
target_link_libraries(mytest.test libTestcase boost_unit_test_framework)

#add_dependencies(${TARGET_SYSTEM}.test stage_ccl)

enable_testing()


