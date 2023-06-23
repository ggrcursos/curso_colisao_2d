file(GLOB_RECURSE libGelRenderIO_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp") 
file(GLOB_RECURSE libGelRenderIO_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp") 

 
set (libGelRenderIO_INCLUDE_DIRS "")
foreach (_headerFile ${libGelRenderIO_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND libGelRenderIO_INCLUDE_DIRS ${_dir})
endforeach()
 
list(REMOVE_DUPLICATES libGelRenderIO_INCLUDE_DIRS)

add_library(GelRenderIO ${libGelRenderIO_SOURCES} ${libGelRenderIO_HEADERS}  ${OPENGL_LIBRARIES}    )
target_include_directories(GelRenderIO PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/")
set_target_properties(GelRenderIO PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${INSTALLATION_PATH}/)
install(TARGETS GelRenderIO DESTINATION ${INSTALLATION_PATH}/)

set(libGelRenderIO_TARGET_LIBRARIES
    ${CMAKE_THREAD_LIBS_INIT} #pthread 
    GelEngine
    glfw
    imgui
    glad
    )
target_link_libraries(GelRenderIO ${libGelRenderIO_TARGET_LIBRARIES}   ${OPENGL_LIBRARIES})