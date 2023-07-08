add_library(algorithms algorithms.cc)

target_include_directories(algorithms PUBLIC ${PROJECT_SOURCE_DIR}/utils)


add_subdirectory(binary_tree)
add_subdirectory(back_tracking)
