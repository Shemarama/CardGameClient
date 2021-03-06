#Specify the version being used as well as the language
cmake_minimum_required(VERSION 2.6)
#Name your project here
project(client)

find_package(wxWidgets COMPONENTS core base REQUIRED)

include( "${wxWidgets_USE_FILE}" )

file(GLOB SRCS *.cpp *.hpp)

if(WIN32)
    set(SRCS ${SRCS} *.rc)
    # add '-mt' to the end of lboost_system and thread for mac, don't for linux
    set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -lboost_system-mt -lboost_thread-mt -lboost_unit_test_framework-mt -lpthread")
endif(WIN32)
if(UNIX)
    # add '-mt' to the end of lboost_system and thread for mac, don't for linux
    set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -lboost_system -lboost_thread -lboost_unit_test_framework -lpthread")
endif(UNIX)
if(APPLE)
    set(SRCS ${SRCS})
    # add '-mt' to the end of lboost_system and thread for mac, don't for linux
    set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -lboost_system-mt -lboost_thread-mt -lboost_unit_test_framework-mt -lpthread")
endif(APPLE)

#This tells CMake to run test.cpp and name it hello
add_executable(client WIN32 ${SRCS})

target_link_libraries(client ${wxWidgets_LIBRARIES})
