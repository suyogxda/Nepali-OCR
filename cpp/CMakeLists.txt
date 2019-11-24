cmake_minimum_required (VERSION 3.5)

project(ocr)
find_package(OpenCV REQUIRED)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")
set (include_dir "${PROJECT_SOURCE_DIR}/include/")

include_directories (${include_dir})
include_directories (${OpenCV_INCLUDE_DIRS})

file (GLOB source_files "${source_dir}/*.cpp")
file (GLOB include_files "${include_dir}/*.h")
file (GLOB ocr "${source_dir}/main.cpp")

add_executable (ocr ${source_files} ${include_files})
target_link_libraries (ocr ${OpenCV_LIBS})
