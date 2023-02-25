CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

PROJECT(sfmlsnake)

FIND_PACKAGE(SFML 2.5 REQUIRED
    system
    window
    graphics)

INCLUDE_DIRECTORIES(include)

ADD_EXECUTABLE(sfmlsnake
    src/SFMLSnake.cpp
    src/main.cpp)

TARGET_LINK_LIBRARIES(sfmlsnake
    sfml-system
    sfml-window
    sfml-graphics)