FILE(GLOB TEST_SOURCES *.cpp)

# Create dependency of MainTest on googletest
ADD_EXECUTABLE(testAbhyas ${TEST_SOURCES})

# Travis CI does not include v2.8.11 of CMake that introduced targed_include_directories
# Work around for the same. Ensure that libtrie directory is added before main and test
INCLUDE_DIRECTORIES(${LIBTRIE_INCLUDES})

TARGET_LINK_LIBRARIES(testAbhyas
    libgtest
    libgmock 
    libtrie
)

ADD_TEST(NAME testAbhyas COMMAND testAbhyas)
