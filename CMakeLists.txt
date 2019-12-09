cmake_minimum_required (VERSION 3.5)
project(DatabaseAccess)

set(DATABASE_ACCESS_VERSION_MAJOR 1)
set(DATABASE_ACCESS_VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Habilitamos testing
enable_testing()
add_subdirectory(test)

# Creamos el ejecutable prinipal y le pegamos la librería
set(SOURCES 
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/DatabaseAccess.cpp
    )
include_directories(
    "${PROJECT_SOURCE_DIR}/include"
    )
add_executable(DatabaseAccess ${SOURCES})

# find_package(Boost COMPONENTS regex system filesystem REQUIRED)
find_package(Boost COMPONENTS system REQUIRED) # por el momento parece que sólo requerimos la de system, ya vermos después
target_link_libraries (
    DatabaseAccess    
    pqxx
    ${Boost_SYSTEM_LIBRARY}        
    )
