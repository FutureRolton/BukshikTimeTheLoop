cmake_minimum_required(VERSION 3.1)

project(BukshikGame)

set(EXECUTABLE_NAME "BukshikGame")

add_executable(${EXECUTABLE_NAME} src/BukshikGame.cpp)

set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

set(CMAKE_FIND_ROOT_PATH "lib/")

find_package(SFML 2.5 COMPONENTS network audio graphics window system REQUIRED)
target_link_libraries(${EXECUTABLE_NAME} sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

set(BOOST_ROOT "lib/")
find_package(Boost 1.7 REQUIRED regex date_time system filesystem thread graph)
include_directories(${BOOST_INCLUDE_DIRS})
target_link_libraries(${EXECUTABLE_NAME} ${Boost_LIBRARIES})

install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")
