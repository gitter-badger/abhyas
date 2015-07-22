# Capture all source files and store them in a variable
file(GLOB MAIN_SOURCES "*.cpp")

# Define the executable and the sources it depends upon
add_executable(abhyas ${MAIN_SOURCES})

# Specify the libraries that this binary depends upon
target_link_libraries(abhyas 
    libtrie
)

