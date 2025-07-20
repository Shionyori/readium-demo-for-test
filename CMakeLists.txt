cmake_minimum_required(VERSION 3.21)

# 让 vcpkg 自动接管依赖
set(CMAKE_TOOLCHAIN_FILE
    "${CMAKE_CURRENT_SOURCE_DIR}/3rd/vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "vcpkg toolchain")

project(readium-demo VERSION 0.1 LANGUAGES CXX)

# Qt 元对象系统
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Qt6
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Poppler (Qt6 后端)
find_package(PkgConfig REQUIRED)
pkg_check_modules(poppler-qt6 REQUIRED IMPORTED_TARGET poppler-qt6)

# 源文件
file(GLOB_RECURSE PROJECT_SOURCES
    src/*.cpp
    src/*.h
)

# 可执行文件
qt_add_executable(readium-demo MACOSX_BUNDLE ${PROJECT_SOURCES})

# 链接
target_link_libraries(readium-demo PRIVATE
    Qt6::Widgets
    PkgConfig::poppler-qt6   # 已包含头文件 + 库
)

# 安装规则
include(GNUInstallDirs)
install(TARGETS readium-demo
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(WIN32)
  add_custom_command(
    TARGET readium-demo 
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
      ${Qt6_DIR}/../../$<$<CONFIG:Debug>:debug/>Qt6/plugins/platforms/
      $<TARGET_FILE_DIR:readium-demo>/platforms/
  ) 
endif()