
file(GLOB_RECURSE projCollision2D_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp") 
file(GLOB_RECURSE projCollision2D_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp") 

 
set (projCollision2D_INCLUDE_DIRS "")
foreach (_headerFile ${projCollision2D_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND projCollision2D_INCLUDE_DIRS ${_dir})
endforeach()
 
list(REMOVE_DUPLICATES projCollision2D_INCLUDE_DIRS)

add_executable(appCollision2D ${projCollision2D_SOURCES} ${projCollision2D_HEADERS}  ${OPENGL_LIBRARIES}    )
add_library(appCollision2Dlb ${projCollision2D_SOURCES} ${projCollision2D_HEADERS}  ${OPENGL_LIBRARIES}    )
target_include_directories(appCollision2D PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/")
set_target_properties(appCollision2D PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${INSTALLATION_PATH}/)
install(TARGETS appCollision2D DESTINATION ${INSTALLATION_PATH})

set(projCollision2D_TARGET_LIBRARIES
    ${CMAKE_THREAD_LIBS_INIT} #pthread 
    GelEngine
    GelRenderIO
    )
target_link_libraries(appCollision2D ${projCollision2D_TARGET_LIBRARIES}  ${OPENGL_LIBRARIES})