file(GLOB SRC_FILES *.cpp)
add_library(mylib ${SRC_FILES})
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})