cmake_minimum_required(VERSION 3.3)
project(rpg_sdl2)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

find_package(BOOST REQUIRED)
include_directories(${BOOST_INCLUDE_DIR})

set(SOURCE_FILES main.cpp test.cpp test.h KeyboardInputHandler.cpp KeyboardInputHandler.h GameState.cpp GameState.h FieldState.cpp FieldState.h World.cpp World.h StateTransition.cpp StateTransition.h Texture.cpp Texture.h Config.h)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${BOOST_LIBRARY} ${SDL2_IMAGE_LIBRARIES})