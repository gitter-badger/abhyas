file(GLOB TEST_SOURCES *.cpp)

# Create dependency of MainTest on googletest
ADD_EXECUTABLE(testAbhyas ${TEST_SOURCES})

TARGET_LINK_LIBRARIES(testAbhyas
    libgtest
    libgmock 
    libtrie
)

add_test(NAME testAbhyas COMMAND testAbhyas)
