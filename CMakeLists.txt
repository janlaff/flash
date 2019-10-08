# cmake_minimum_required(VERSION <specify CMake version here>)
project(flash)

set(CMAKE_CXX_STANDARD 17)

set(
        SOURCE_FILES
        ecs/EntityManager.cpp
        ecs/SystemManager.cpp
        ecs/ComponentManager.cpp
        ecs/EntityComponentSystem.cpp
        log/Logger.cpp
        log/ConsoleLogger.cpp
        log/Log.cpp
        ui/UiSystem.cpp
)

add_library(flash ${SOURCE_FILES})

add_executable(flash-main main.cpp)
target_link_libraries(flash-main flash)