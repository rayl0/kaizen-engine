cmake_minimum_required(VERSION 3.7)
project(kaizen VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(SFML COMPONENTS window graphics system REQUIRED)

add_subdirectory(external EXCLUDE_FROM_ALL)

add_executable(kaizen source/kaizen/main.cc source/kaizen/ecs/ecs.h)

target_include_directories(kaizen
    PRIVATE 
        ${CMAKE_SOURCE_DIR}/source
        ${CMAKE_SOURCE_DIR}/source/kaizen
)

target_link_libraries(kaizen 
    PRIVATE 
        sfml-window
        sfml-graphics
        sfml-system
        entityx::entityx
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
