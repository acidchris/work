project(testbed)

set(CMAKE_SUPPRESS_REGENERATION true)

set(SOURCE_FILES main.cpp)
#set(HEADER_FILES header.h)


add_executable(testbed ${SOURCE_FILES})

add_dependencies(testbed sgf)


target_link_libraries(testbed sgf)