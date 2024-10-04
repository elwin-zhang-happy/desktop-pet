cmake_minimum_required(VERSION 3.5)
project(desktop_pet)
# 设置C++标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
# 设置ui文件
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/main/ui_include)

if(WIN32)
    set(CMAKE_PREFIX_PATH "D:/qtcreater/6.6.1/mingw_64")
else ()
    set(CMAKE_PREFIX_PATH "/Users/elwinzhang/Qt/6.7.2/macos" ${CMAKE_PREFIX_PATH})
endif ()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Core Gui LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core Gui LinguistTools)

# 如果找到OpenCV包，将OpenCV_INCLUDE_DIRS添加到include路径
if(OpenCV_FOUND)
    find_package(OpenCV REQUIRED)
    include_directories(${OpenCV_INCLUDE_DIRS})
endif()

# 头文件
include_directories(${CMAKE_SOURCE_DIR}/main/include
        ${CMAKE_SOURCE_DIR}/main/ui_include
        ${CMAKE_SOURCE_DIR}/main/lib
)
# 源文件
file(GLOB_RECURSE SOURCE_FILES
        "main.cpp"
        "main/source/*.cpp"
        "main/include/*.h"
        "main/ui_include/*.ui"
        #        ${CMAKE_SOURCE_DIR}/main/lib/*
)
# qt资源文件
set(QRC_SOURCE_FILES main/res.qrc)
qt_add_resources(${QRC_SOURCE_FILES})

#设置目标文件输出目录
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(LINK_LIBS)

if (WIN32)
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES} ${QRC_SOURCE_FILES})
else ()
    # 设置为图形界面应用
    set(CMAKE_MACOSX_BUNDLE TRUE)

    add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${QRC_SOURCE_FILES})
endif ()

target_link_libraries(${PROJECT_NAME}
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Gui
        Qt${QT_VERSION_MAJOR}::Widgets
        #        Qt6::Network
        #        Qt6::PrintSupport
        #        Qt6::Designer
        #        Qt6::WebEngineWidgets
        #        Qt6::Sql
        #        ${LINK_LIBS}
)

# 设置输出目录为 .app 包
set_target_properties(${PROJECT_NAME} PROPERTIES MACOSX_BUNDLE YES)
set_target_properties(${PROJECT_NAME} PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME "${PROJECT_NAME}.app")

# 复制 Info.plist 到构建目录
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/Info.plist $<TARGET_FILE_DIR:${PROJECT_NAME}>/Contents/Info.plist
)


if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
