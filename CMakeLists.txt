cmake_minimum_required(VERSION 3.28)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

# Busca y configura GTK
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

# Añade tu ejecutable
add_executable(untitled main.cpp
        Lista.cpp
        Lista.h
        Sorter.h
        Sorter.cpp
        BinarySearchTree.h
        BinarySearchTree.cpp
        peorcaso.h
        mejorcaso.h
        promedio.h)

# Incluye los directorios de GTK
target_include_directories(untitled PRIVATE ${GTK3_INCLUDE_DIRS})

# Vincula las bibliotecas de GTK
target_link_libraries(untitled ${GTK3_LIBRARIES})
