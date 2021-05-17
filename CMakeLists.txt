cmake_minimum_required(VERSION 3.1.3)
project(graphyUI CXX)

add_subdirectory(graphy-json-module/lib)
add_subdirectory(graphy-qml-engine/lib)
add_subdirectory(graphy-qml-file-selector-module/lib)
add_subdirectory(graphy-rest-service/lib)

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
       

find_package(Qt5Concurrent CONFIG REQUIRED)
find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5DBus CONFIG REQUIRED)
find_package(Qt5Xml CONFIG REQUIRED)
find_package(Qt5Gui CONFIG REQUIRED)
find_package(Qt5Network CONFIG REQUIRED)
find_package(Qt5OpenGL CONFIG REQUIRED)
find_package(Qt5OpenGLExtensions CONFIG REQUIRED)
find_package(Qt5PrintSupport CONFIG REQUIRED)
find_package(Qt5Sql CONFIG REQUIRED)
find_package(Qt5Test CONFIG REQUIRED)
find_package(Qt5Widgets CONFIG REQUIRED)                

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) 

file(GLOB INC ${PROJECT_SOURCE_DIR}/src/*.h)
file(GLOB SRC ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(${PROJECT_NAME} ${INC} ${SRC})
conan_target_link_libraries(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} 
Qt5::Concurrent
Qt5::Core
Qt5::DBus
Qt5::Xml
Qt5::Gui
Qt5::Network
Qt5::OpenGL
Qt5::OpenGLExtensions
Qt5::PrintSupport
Qt5::Sql
Qt5::Test
Qt5::Widgets 
graphyRestServiceLib 
graphyQmlFileSelectorModuleLib 
graphyQmlEngineLib 
graphyJsonModuleLib)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
