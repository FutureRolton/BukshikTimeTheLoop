cmake_minimum_required(VERSION 3.13)

project(BukshikGame)

set(EXECUTABLE_NAME "BukshikGame")

add_executable(${EXECUTABLE_NAME} BukshikGame.cpp)

set(SOURCE_EXE BukshikGame.cpp)

include_directories(headers)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
else()
  message(SEND_ERROR "Failed to find sfml")
endif()

install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
