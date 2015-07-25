# Capture all source files and store them in a variable
FILE(GLOB MAIN_SOURCES "*.cpp")

# Define the executable and the sources it depends upon
ADD_EXECUTABLE(abhyas ${MAIN_SOURCES})

# Travis CI offers only CMake v2.8.7 which does not support target_include_directories
INCLUDE_DIRECTORIES(${LIBTRIE_INCLUDES})

# Specify the libraries that this binary depends upon
TARGET_LINK_LIBRARIES(abhyas 
    libtrie
)

