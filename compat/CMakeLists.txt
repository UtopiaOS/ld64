

add_library(helper STATIC helper.c)

target_include_directories(helper PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)