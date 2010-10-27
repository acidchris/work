# List all include directories used for the project
set(INCLUDE_DIRS
    .
    ./property_system
   )

# List all source files
set(SOURCE_FILES
    ./property_system/property_list.cpp
   )

# List all header files
set(HEADER_FILES
    ./property_system/property_list.h
   )


# Set project options
include_directories(${INCLUDE_DIRS})

# Set the target
add_library(sgf STATIC ${SOURCE_FILES} ${HEADER_FILES})
