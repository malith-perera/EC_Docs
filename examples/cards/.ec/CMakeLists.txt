cmake_minimum_required(VERSION 3.22)
project(cards)

set(CMAKE_BUILD_TYPE Debug)  #Debug #Release

#selecting the build mode in their IDE
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb3 -O0 --std=c11 -Wall -lm")
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
set (PROJECT_INCLUDE_DIRS ${PARENT_DIR}/src ${PARENT_DIR}/include ${PARENT2_DIR}/EC/src "/usr/local/include")
include_directories(${PROJECT_INCLUDE_DIRS})

set (PROJECT_LINK_DIRS ${PARENT2_DIR}/EC)
set (PROJECT_LINK_LIBS libEC.so)
link_directories (${PROJECT_LINK_DIRS})

#However, the file(GLOB...) allows for wildcard additions
file(GLOB SOURCE_FILES "${PARENT_DIR}/src/*.c")

add_executable(cards ${SOURCE_FILES})
target_link_libraries(cards ${PROJECT_LINK_LIBS})
