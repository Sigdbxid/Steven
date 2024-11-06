cmake_minimum_required(VERSION 3.29)
project(SnakeGame)

# 设置C++标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# 设置SDL2路径（如果需要）
set(SDL2_PATH /Library/Frameworks/SDL2.framework)
list(APPEND CMAKE_PREFIX_PATH ${SDL2_PATH})

# 查找SDL2库
find_package(SDL2 REQUIRED)

# 包含SDL2头文件目录
include_directories(${SDL2_INCLUDE_DIRS})
aux_source_directory(. SRC_LIST)
# 添加可执行文件
add_executable(SnakeGame ${SRC_LIST})

# 链接SDL2库
target_link_libraries(SnakeGame ${SDL2_LIBRARIES})

