cmake_minimum_required(VERSION 3.20)
project(my_sqlite)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подключаем папку с заголовочными файлами
include_directories(include)

# Собираем все cpp файлы из src/core
file(GLOB_RECURSE CORE_SOURCES "src/core/*.cpp")

# Создаем исполняемый файл
add_executable(my_sqlite
        main.cpp
        ${CORE_SOURCES}
)