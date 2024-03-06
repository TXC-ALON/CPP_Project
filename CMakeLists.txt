cmake_minimum_required(VERSION 3.5)

project(MyProject)

# 设置库文件路径和名称
set(LIB_PATH ${CMAKE_SOURCE_DIR}/lib)
set(EXTERNAL_PATH ${CMAKE_SOURCE_DIR}/external)
set(SPDLOG_PATH ${EXTERNAL_PATH}/spdlog)

# 设置SPDLOG库的一些lib
set(SPDLOG_INCLUDE_DIR ${SPDLOG_PATH}/include)
set(SPDLOG_LIB ${SPDLOG_PATH}/lib/spdlog.lib)
set(SPDLOG_LIB_D ${SPDLOG_PATH}/lib/spdlogd.lib)

# 可以继续添加其他库的路径和名称

# 添加可执行文件
add_executable(MyProject src/main.cpp)

# 链接 spdlog 库
target_include_directories(MyProject PRIVATE ${SPDLOG_INCLUDE_DIR})
target_link_libraries(MyProject PRIVATE ${SPDLOG_LIB})