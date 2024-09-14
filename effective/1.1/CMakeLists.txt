# 指定CMake的最低版本要求为3.30.3。CMake的版本必须大于或等于这个版本。
cmake_minimum_required(VERSION 3.30.3)

# 设置工程名称为1.1，版本为1.0
project(1.1 VERSION 1.0)

# 设置C++标准为C++20
set(CMAKE_CXX_STANDARD 20)

# 确保使用的C++标准是指定的标准
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 设置可执行文件的输出目录为构建目录下的bin文件夹
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 包含指定的头文件目录，以便编译器可以找到头文件
include_directories(${PROJECT_SOURCE_DIR}/include)

# 添加可执行文件目标，源文件包含
add_executable(1.1 main.cpp src/test.cpp src/demo.cpp)
