
file(GLOB_RECURSE CPPS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp") 
file(GLOB_RECURSE HPPS "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp") 

file(GLOB SRC_FILES *.cpp)
set (INCLUDE_DIRS "")
foreach (_headerFile ${HPPS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND INCLUDE_DIRS ${_dir})
endforeach()
 
list(REMOVE_DUPLICATES INCLUDE_DIRS)


add_executable( testCollision2D ${SRC_FILES} ${INCLUDE_DIRS})  

target_link_libraries(testCollision2D
 PRIVATE
  GTest::gtest_main
  GelEngine
  GelRenderIO
  appCollision2Dlb
  )

 