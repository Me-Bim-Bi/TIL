cmake_minimum_required(VERSION 3.29)
project(Lab1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab1 main.cpp
        Dice.cpp
        Dice.h
        DiceRoller.cpp
        DiceRoller.h
        main.cpp
        DiceRollerFactory.cpp
        DiceRollerFactory.h
        Player.cpp
        Player.h
        game.cpp
        game.h
        utils.cpp
        utils.h)
