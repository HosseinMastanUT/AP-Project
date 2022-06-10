 cmake_minimum_required(VERSION 3.1.0)
 project(Chess)

 set(CMAKE_CXX_STANDARD 11)

 set(SRC_DIRECTORY Source)
 set(INCLUDE_DIRECTORY Headers)

 set(SOURCES
    ${SRC_DIRECTORY}/Board.cpp
)

include_directories(${INCLUDE_DIRECTORY})
add_executable(${PROJECT_NAME}
    ${SRC_DIRECTORY}/main.cpp
    ${SOURCES}
)

target_link_libraries(${PROJECT_NAME}
    sfml-system
    sfml-window
    sfml-graphics
    sfml-audio
)