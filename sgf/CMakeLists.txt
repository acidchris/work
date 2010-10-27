# List all include directories used for the project
set(INCLUDE_DIRS
    .
    ./property_system
   )

# List all source files
set(PROPERTY_SYSTEM_FILES
    ./property_system/property_list.cpp
    ./property_system/property_list.h
   )

# Map them together
set(SOURCE_FILES ${PROPERTY_SYSTEM_FILES})

source_group("Property System" FILES ${PROPERTY_SYSTEM_FILES})

set(MODULE_FILES ./CMakeLists.txt)

# Set project options
include_directories(${INCLUDE_DIRS})

# Set the target
add_library(sgf STATIC ${SOURCE_FILES} ${MODULE_FILES})
