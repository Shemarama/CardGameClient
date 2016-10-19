#Specify the version being used as well as the language
cmake_minimum_required(VERSION 2.6)
#Name your project here
project(client)

find_package(wxWidgets COMPONENTS core base REQUIRED)

include( "${wxWidgets_USE_FILE}" )

file(GLOB SRCS *.cpp *.hpp)

if(WIN32)
    set(SRCS ${SRCS} *.rc)
endif(WIN32)

set(CMAKE_CXX_FLAGS "-std=c++11 -lboost_system -lboost_thread -lpthread")

#This tells CMake to run test.cpp and name it hello
add_executable(client WIN32 ${SRCS})

target_link_libraries(client ${wxWidgets_LIBRARIES})
