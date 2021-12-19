cmake_minimum_required (VERSION 3.8)

include_directories("../include")

set(BINARY ${CMAKE_PROJECT_NAME})
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.c *.cpp)
set(SOURCES ${SOURCES})

add_executable(${BINARY}_run ${SOURCES})

IF (WIN32)
    set_target_properties(${BINARY}_run PROPERTIES
    LINK_FLAGS "/ENTRY:mainCRTStartup /SUBSYSTEM:WINDOWS")
ENDIF()
