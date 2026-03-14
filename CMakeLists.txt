cmake_minimum_required(VERSION 4.0)
project(OOP_3_2)

set(CMAKE_CXX_STANDARD 20)

find_package(Catch2 3 REQUIRED)

add_executable(
        OOP_3_2
        main.cpp
        src/car/Car.cpp
        src/car/Car.h
        src/engine/Engine.cpp
        src/engine/Engine.h
        src/engine/IEngine.h
        src/car/ICar.h
        src/gearBox/GearBox.cpp
        src/gearBox/GearBox.h
        src/gearBox/IGearBox.h
        src/types.h
        src/cli/CLI.cpp
        src/cli/CLI.h
)

add_executable(
        GearBoxTest
        src/gearBox/test/GearBoxTest.cpp
        src/gearBox/GearBox.h
        src/gearBox/GearBox.cpp
)

add_executable(
        EngineTest
        src/engine/test/EngineTest.cpp
        src/engine/Engine.h
        src/engine/Engine.cpp
)

add_executable(
        CarTest
        src/car/test/CarTest.cpp
        src/car/Car.cpp
        src/car/Car.h
        src/engine/Engine.h
        src/engine/Engine.cpp
        src/gearBox/GearBox.h
        src/gearBox/GearBox.cpp
        src/cli/CLI.cpp
        src/cli/CLI.h
        src/suspension/Suspension.cpp
        src/suspension/Suspension.h
        src/suspension/ISuspension.h
)

add_executable(
        DestructorTest
        DestructorTest.cpp
)

target_link_libraries(GearBoxTest PRIVATE Catch2::Catch2WithMain)
target_link_libraries(EngineTest PRIVATE Catch2::Catch2WithMain)
target_link_libraries(CarTest PRIVATE Catch2::Catch2WithMain)