file(GLOB_RECURSE testGelEngine_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp") 
file(GLOB_RECURSE testGelEngine_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp") 

set (INCLUDE_DIRS "")
foreach (_headerFile ${testGelEngine_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND INCLUDE_DIRS ${_dir})
endforeach()
 
list(REMOVE_DUPLICATES INCLUDE_DIRS)


add_executable( testGelEngine ${testGelEngine_SOURCES} ${INCLUDE_DIRS}) 

target_link_libraries(testGelEngine
 PRIVATE
  GTest::gtest_main
  GelEngine
  )

 