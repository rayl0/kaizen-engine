cmake_minimum_required(VERSION 3.0.0)
project(kaizen VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(SFML COMPONENTS window graphics system REQUIRED)

add_executable(kaizen source/kaizen/main.cc)

target_link_libraries(kaizen 
    PRIVATE 
        sfml-window
        sfml-graphics
        sfml-system
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
