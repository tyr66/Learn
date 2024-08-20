cmake_minimum_required(VERSION 3.10) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_TOOLCHAIN_FILE "D:/worksoftware/vcpkg/scripts/buildsystems/vcpkg.cmake")
# 设置 CMAKE_EXPORT_COMPILE_COMMANDS 选项为 ON, 用来生成compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(TBBProject LANGUAGES CXX)


add_executable(main main.cpp)

find_package(TBB REQUIRED)
target_link_libraries(main PUBLIC TBB::tbb)

