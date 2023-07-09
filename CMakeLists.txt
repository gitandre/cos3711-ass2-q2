cmake_minimum_required(VERSION 3.25)
project(cos3711_ass2_q2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(cos3711_ass2_q2 main.cpp Stock.h Confectionary.h ReadingMaterial.h)
target_link_libraries(cos3711_ass2_q2
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

