
cmake_minimum_required(VERSION 2.6)

# Only the basics
if (WIN32)
  set(CMAKE_USE_RELATIVE_PATHS true)
  set(CMAKE_SUPPRESS_REGENERATION true)
endif()

# fetch environment variable and store internally
set(OGRE_SDK_ROOT $ENV{OGRE_SDK})
set(OGRE_SDK_INCLUDES ${OGRE_SDK_ROOT}/include/OGRE)

# quick check if it exists (is used later for include directories)
if (OGRE_SDK_ROOT)
  message("OGRE_SDK environment variable mappend to: ${OGRE_SDK_ROOT}")
elseif (NOT OGRE_SDK_ROOT) 
  message("OGRE_SDK environment variable not set")
endif ()

# define the solution
project(work)

# add directories for further search
add_subdirectory(sgf)
add_subdirectory(testbed)
