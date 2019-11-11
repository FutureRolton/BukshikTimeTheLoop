cmake_minimum_required(VERSION 3.1)

project(BukshikGame)

set(EXECUTABLE_NAME "BukshikGame")

add_executable(${EXECUTABLE_NAME} src/BukshikGame.cpp)

set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_BUILD_TYPE Debug)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/lib" ${CMAKE_MODULE_PATH})

set(CMAKE_FIND_ROOT_PATH "lib/")

# SFML
# FIXME!
#set(SFML_ROOT "lib/SFML/")
set(SFML_DIR "lib/SFML/lib/cmake/SFML/")
find_package(SFML 2.5 COMPONENTS network audio graphics window system REQUIRED NO_DEFAULT_PATH)
target_link_libraries(${EXECUTABLE_NAME} sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
#target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
include_directories(${SFML_INCLUDE_DIR})

# BOOST
set(BOOST_ROOT "lib/boost/")
set(Boost_DIR "lib/boost/cmake/Boost-1.71.0/")

set(Boost_USE_STATIC_LIBS OFF )
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost REQUIRED COMPONENTS regex date_time system filesystem thread graph NO_DEFAULT_PATH)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(${EXECUTABLE_NAME} ${Boost_LIBRARIES})

# FIXME!
set(nlohmann_json_DIR "lib/json/")

find_package(nlohmann_json 3.2.0 REQUIRED)
target_link_libraries(${EXECUTABLE_NAME} nlohmann_json::nlohmann_json)

# Include User header
file(GLOB SOURCES
  src/include/*.hpp
  src/include/*.cpp
)
add_executable( TARGETS ${SOURCES} )

install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")
