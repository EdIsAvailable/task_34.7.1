cmake_minimum_required(VERSION 3.10.0)
project(task_34.7.1 VERSION 0.1.0 LANGUAGES C CXX)

# Включаем поддержку C++20 для концептов
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Создаем исполняемый файл
add_executable(complex_concept_demo 
    main.cpp
    ComplexConcept.cpp
)

# Подключаем заголовочные файлы
target_include_directories(complex_concept_demo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Опционально: Для более строгой компиляции
if(MSVC)
    target_compile_options(complex_concept_demo PRIVATE /W4)
else()
    target_compile_options(complex_concept_demo PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Включаем тестирование (если нужно)
include(CTest)
enable_testing()

# Опционально: настройка упаковки
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)