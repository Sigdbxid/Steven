cmake_minimum_required(VERSION 3.29)
project(SnakeGame)

# 设置C++标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SDL2 REQUIRED PATHS /opt/homebrew/include/SDL2)
find_package(SDL2_ttf REQUIRED PATHS /opt/homebrew/include/SDL2)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})
link_directories(/opt/homebrew/lib)
aux_source_directory(. SRC_FILES)

add_executable(SnakeGame ${SRC_FILES})

target_link_libraries(SnakeGame SDL2 SDL2_ttf)