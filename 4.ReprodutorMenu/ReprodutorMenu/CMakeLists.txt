cmake_minimum_required(VERSION 3.5)

project(ReprodutorMenu VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Encontra as libs!
find_package(Qt5 COMPONENTS Multimedia REQUIRED)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

find_package(Qt5 ${USED_QT_VERSION} REQUIRED COMPONENTS
    Core
    Gui
    Widgets
    Multimedia
    MultimediaWidgets
)

# Inclui as libs
include_directories(
    ${Qt5Core_INCLUDE_DIRS}
    ${Qt5Gui_INCLUDE_DIRS}
    ${Qt5Widgets_INCLUDE_DIRS}
    ${Qt5PrintSupport_INCLUDE_DIRS}
    ${Qt5Sql_INCLUDE_DIRS}
    ${Qt5Multimedia_INCLUDE_DIRS}
    ${Qt5MultimediaWidgets_INCLUDE_DIRS}
)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        recursos.qrc

        arquivos.cpp
        arquivos.h

        usuario.cpp
        usuario.h

        videographicsview.cpp
        videographicsview.h

        reprodutor.h
        reprodutor.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ReprodutorMenu
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ReprodutorMenu APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ReprodutorMenu SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ReprodutorMenu
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Linka as libs !
target_link_libraries(ReprodutorMenu PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(ReprodutorMenu PRIVATE Qt${QT_VERSION_MAJOR}::Multimedia)
target_link_libraries(ReprodutorMenu PRIVATE Qt5::Core)
target_link_libraries(ReprodutorMenu PRIVATE Qt5::Gui)
target_link_libraries(ReprodutorMenu PRIVATE Qt${QT_VERSION_MAJOR}::MultimediaWidgets)

set_target_properties(ReprodutorMenu PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ReprodutorMenu)
endif()
