cmake_minimum_required(VERSION 3.10.2)
project(test)

set(CMAKE_BUILD_TYPE DEBUG)  #Release type

# selecting the build mode in their IDE
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  `--libs --cflags` -ggdb3 -O0 --std=c11 -Wall -lm")
	set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
	set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
	if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else ()
		set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
	endif ()
endif ()


get_filename_component(PARENT_DIR ${PROJECT_SOURCE_DIR} DIRECTORY)
get_filename_component(PARENT2_DIR ${PARENT_DIR} DIRECTORY)

#Set include directories
set (PROJECT_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}")
include_directories (${PROJECT_INCLUDE_DIRS} "${PARENT_DIR}/src" "${PARENT2_DIR}/src")

set (PROJECT_LINK_LIBS libEC.so)
set (PROJECT_LINK_DIRS "${PARENT2_DIR}")
link_directories (${PROJECT_LINK_DIRS})

#file(GLOB...) allows wildcard additions
file(GLOB SOURCES_FILES "${PARENT_DIR}/src/*.c")

#Generate executable from the sources
add_executable(${PROJECT_NAME} ${SOURCES_FILES})
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${PROJECT_LINK_LIBS} m)

#message ("${PROJECT_SOURCE_DIR}")
