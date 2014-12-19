cmake_minimum_required( VERSION 2.8 )
project(Firewalker)
set(HEADERS
	svsp.h)
set(SOURCES
	svsp.cpp
	main.cpp)
set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
add_executable(
	${PROJECT_NAME}
	${HEADERS}
	${SOURCES})
add_custom_command(
	TARGET ${PROJECT_NAME}
	POST_BUILD
	COMMAND doxygen)
add_custom_command(
	TARGET ${PROJECT_NAME}
	POST_BUILD
	COMMAND cppcheck ${SOURCES}	svsp.h	2>analysis.txt)
