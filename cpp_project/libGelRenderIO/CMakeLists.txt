
 

cmake_minimum_required(VERSION 3.11)

project("libGelRender")
 
option(RENDER_LIB_TEST "Enable/Disable tests" OFF)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)
SET(CMAKE_BUILD_TYPE Debug) 
SET(LIBRARIES_INCLUDE_PATH "usr/local/include")
SET(LIBRARIES_PATH "/usr/loca/lib64")
SET(LIBRARIES_LIB_PATH "/usr/local/lib")
 

include_directories(src/include)


# IF(${RENDER_LIB_TEST})
#     include(FetchContent)
#     FetchContent_Declare(
#     googletest
#     URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
#     )
#     # For Windows: Prevent overriding the parent project's compiler/linker settings
#     set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#     FetchContent_MakeAvailable(googletest)

#     add_subdirectory(test)
# ENDIF()


find_package(OpenGL REQUIRED)
#]
if (NOT OPENGL_FOUND) 
    return()
endif ()
include(FetchContent) 

set(BUILD_LIBS_PATH build/_deps)


set(GLAD_INCLUDE_PATH build/_deps/glad_new_lib-build/include)
# set(GLAD_LIB_SOURCE ${BUILD_LIBS_PATH}/)
#Add Glad 
FetchContent_Declare(glad  GIT_REPOSITORY https://github.com/Dav1dde/glad.git GIT_TAG df8e9e16110b305479a875399cee13daa0ccadd9)
FetchContent_MakeAvailable(glad )

#Add GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
FetchContent_Declare(glfw GIT_REPOSITORY https://github.com/glfw/glfw.git GIT_TAG 3.3.2)
FetchContent_MakeAvailable(glfw)

target_compile_options(glfw PRIVATE -Wno-pedantic  -Wno-unused-parameter)

#ImgGui
FetchContent_Declare(
        imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui.git
        GIT_TAG v1.77
)
FetchContent_GetProperties(imgui)
# if (NOT imgui_POPULATED)
    FetchContent_Populate(imgui)
    set(IMGUI_INCLUDE_DIR ${imgui_SOURCE_DIR}/)
    file(GLOB IMGUI_SOURCES ${imgui_SOURCE_DIR}/*.cpp)
    file(GLOB IMGUI_HEADERS ${imgui_SOURCE_DIR}/*.h)
    add_library(imgui STATIC ${IMGUI_SOURCES} ${IMGUI_SOURCES} ${imgui_SOURCE_DIR}/examples/imgui_impl_glfw.cpp ${imgui_SOURCE_DIR}/examples/imgui_impl_opengl3.cpp)
    add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_GLAD)
    target_include_directories(imgui PUBLIC ${IMGUI_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLFW_INCLUDE_DIR} ${GLAD_INCLUDE_DIR})
    target_link_libraries(imgui ${OPENGL_LIBRARIES} glfw glad)
# endif ()

add_subdirectory(src)


 

 
 