cmake_minimum_required(VERSION 3.0.0)
project(mdparser-cpp VERSION 0.1.0)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(${PROJECT_NAME}
        src/WotoMd.cpp
        src/WotoMd.h)

set_target_properties(${PROJECT_NAME} PROPERTIES
        PUBLIC_HEADER "src/WotoMd.cpp;src/WotoMd.h"
        )
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS mdparser-cpp EXPORT ${PROJECT_NAME}Targets
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION include/${PROJECT_NAME})