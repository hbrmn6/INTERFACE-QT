cmake_minimum_required(VERSION 3.5)

project(tp1 LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt6 COMPONENTS Widgets REQUIRED) # QWidget
add_executable(tp1 main.cpp calculatrice.cpp calculatrice.h model.cpp model.h  )

target_link_libraries(tp1 PRIVATE Qt6::Widgets)
