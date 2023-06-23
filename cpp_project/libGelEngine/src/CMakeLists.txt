# buscar recursivamente pastas para listar cpp`s e hpp`s
file(GLOB_RECURSE libGelEngine_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp") 
file(GLOB_RECURSE libGelEngine_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp") 
# percorrer lista de includes e remover duplicados
set (libGelEngine_INCLUDE_DIRS "")
foreach (_headerFile ${libGelEngine_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND libGelEngine_INCLUDE_DIRS ${_dir})
endforeach()
 
list(REMOVE_DUPLICATES libGelEngine_INCLUDE_DIRS)
# adicionar lib ou executavel
add_library(GelEngine ${libGelEngine_SOURCES} ${libGelEngine_HEADERS}  ${OPENGL_LIBRARIES}    )
# setar os targets(diretorios, install...)
target_include_directories(GelEngine PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/")
set_target_properties(GelEngine PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${INSTALLATION_PATH})
install(TARGETS GelEngine DESTINATION ${INSTALLATION_PATH})

# linkar dependencias na lib ou no executavel
set(libGelEngine_TARGET_LIBRARIES
    ${CMAKE_THREAD_LIBS_INIT} #pthread 
    )
target_link_libraries(GelEngine ${libGelEngine_TARGET_LIBRARIES} ${OPENGL_LIBRARIES})
 