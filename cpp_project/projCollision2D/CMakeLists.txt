cmake_minimum_required(VERSION 3.11)

PROJECT("projCollision2D")

OPTION(COLLISION2D_LIB_TEST "Enable/Disable tests" OFF)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)
SET(CMAKE_BUILD_TYPE Debug)
SET(INSTALLATION_PATH ${CMAKE_BINARY_DIR}/Debug) 
SET(LIBRARIES_INCLUDE_PATH "usr/local/include")
SET(LIBRARIES_PATH "/usr/loca/lib64")
SET(LIBRARIES_LIB_PATH "/usr/local/lib")

include_directories(src/include)
if(${COLLISION2D_LIB_TEST})
    include(FetchContent)
    FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    add_subdirectory(test)
endif()
 
 
add_subdirectory(src)

 




 