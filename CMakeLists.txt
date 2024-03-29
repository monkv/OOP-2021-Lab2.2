cmake_minimum_required(VERSION 3.20)
project(LABA2)

set(CMAKE_CXX_STANDARD 20)

add_executable(LABA2 main.cpp binary.h binary.cpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(test bin_test.cpp binary.h)
target_link_libraries(test gtest_main)
add_test(NAME bin_test COMMAND test)