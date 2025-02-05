cmake_minimum_required(VERSION 3.29)
project(Lab3)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab3 main.cpp
        Stock.h
        Stock.cpp
        Notepad.h
        Notepad.cpp
        ToiletRolls.h
        ToiletRolls.cpp
        Article.h
        Article.cpp
        Glasses.h
        SunGlasses.h
        StockGlasses.h
        ReadingGlasses.h
        Glasses.cpp
        ReadingGlasses.cpp
        StockGlasses.cpp
        SunGlasses.cpp)
