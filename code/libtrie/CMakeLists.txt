# Define the files that make this library
set(LIBTRIE_SOURCES trie.h trie.cpp)

# Declare the static library
add_library(libtrie STATIC ${LIBTRIE_SOURCES})

# Specify here the include directories exported by this library
target_include_directories(libtrie PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
