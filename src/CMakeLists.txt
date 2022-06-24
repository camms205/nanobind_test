file(GLOB SRC_FILES *.cpp)
add_executable(test ${SRC_FILES})
set_target_properties(test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
target_link_libraries(test LINK_PUBLIC mylib)