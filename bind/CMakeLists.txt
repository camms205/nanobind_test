find_package(Python COMPONENTS Interpreter Development REQUIRED)

add_subdirectory(nanobind)

file(GLOB SRC_FILES *.cpp)
nanobind_add_module(mymodule ${SRC_FILES})
target_link_libraries(mymodule LINK_PUBLIC mylib)
target_include_directories(mymodule PUBLIC ${CMAKE_BINARY_DIR}/lib)