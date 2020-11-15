
cmake_minimum_required(VERSION 3.1.3)
project(graphyUI CXX)

add_subdirectory(graphy-json-module/lib)
add_subdirectory(graphy-qml-engine/lib)
add_subdirectory(graphy-qml-file-selector-module/lib)
add_subdirectory(graphy-rest-service/lib)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_VERBOSE_MAKEFILE TRUE)

# Turn on automatic invocation of the MOC, UIC & RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
                  "${CMAKE_CURRENT_BINARY_DIR}/conan.cmake")
endif()
include(${CMAKE_CURRENT_BINARY_DIR}/conan.cmake)
conan_cmake_run(CONANFILE conanfile.txt
                BASIC_SETUP CMAKE_TARGETS
                BUILD missing)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) 

# Make this a GUI application on Windows
if(WIN32)
  set(CMAKE_WIN32_EXECUTABLE ON)
endif()

# Find the QtWidgets library
#find_package(Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt5Core CONFIG REQUIRED)

file(GLOB INC ${PROJECT_SOURCE_DIR}/src/*.h)
file(GLOB SRC ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(${PROJECT_NAME} ${INC} ${SRC})
conan_target_link_libraries(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} graphyRestServiceLib graphyQmlFileSelectorModuleLib graphyQmlEngineLib graphyJsonModuleLib)
#target_link_libraries(${PROJECT_NAME})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
