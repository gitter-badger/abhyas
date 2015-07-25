# Define the files that make this library
SET(LIBTRIE_SOURCES trie.h trie.cpp)

# Declare the static library
ADD_LIBRARY(libtrie STATIC ${LIBTRIE_SOURCES})

# Travis CI offers only CMake v2.8.7 which does not support target_include_directories
SET(LIBTRIE_INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}" CACHE INTERNAL
    "Public include path(s) for libtrie")

# Specify here the include directories exported by this library
#TARGET_INCLUDE_DIRECTORIES(libtrie PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
