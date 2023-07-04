cmake_minimum_required(VERSION 3.20)


 
include_directories(libGelEngine/src/include)
include_directories(libGelRenderIO/src/include) 
# include_directories(projCollision2D/src/include) 

add_subdirectory(libGelEngine)
add_subdirectory(libGelRenderIO) 
# add_subdirectory(projCollision2D)