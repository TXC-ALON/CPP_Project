cmake_minimum_required(VERSION 3.11)

project(MyProject)

#检查系统
MESSAGE("Identifying the OS...")
if(WIN32)
  MESSAGE("This is Windows.")
elseif(APPLE)
  MESSAGE("This is MacOS.")
elseif(UNIX)
  MESSAGE("This is Linux.")
endif()

#基本配置
set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_BUILD_TYPE "Debug")  # Debug模式 选项: Release Debug MinSizeRel RelWithDebInfo
# SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")  # debug模式下 gdb相关选项
# SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall") # release模式下 gdb相关选项
add_definitions(-DDEBUG) # 相当于代码中 #define DEBUG
# add_subdirectory(test) # 添加test子目录
SET(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin") # 可执行文件输出目录
INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/include") # 头文件包含目录
AUX_SOURCE_DIRECTORY(src DIR_SRCS) # 添加源代码文件夹, 自动扫描所有文件


# 设置库文件路径和名称
set(LIB_PATH ${CMAKE_SOURCE_DIR}/lib)
set(EXTERNAL_PATH ${CMAKE_SOURCE_DIR}/external)
set(SPDLOG_PATH ${EXTERNAL_PATH}/spdlog)

# 设置SPDLOG库的一些lib
set(SPDLOG_INCLUDE_DIR ${SPDLOG_PATH}/include)
message(STATUS "SPDLOG_INCLUDE_DIR IS ${SPDLOG_INCLUDE_DIR}")
set(SPDLOG_LIB ${SPDLOG_PATH}/lib/spdlog.lib)
set(SPDLOG_LIB_D ${SPDLOG_PATH}/lib/spdlogd.lib)

# 可以继续添加其他库的路径和名称

# 添加可执行文件
add_executable(MyProject  # 输出名为chess的可执行文件
   ${DIR_SRCS}
)
#add_executable(MyProject src/main.cpp)

# 链接 spdlog 库
target_include_directories(MyProject PRIVATE ${SPDLOG_INCLUDE_DIR})
target_link_libraries(MyProject PRIVATE ${SPDLOG_LIB})

add_subdirectory(test) # 添加test子目录