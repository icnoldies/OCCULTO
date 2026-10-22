
cmake_minimum_required(VERSION 3.20)

project(OCCULTO)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

find_package(OpenCV REQUIRED)

add_executable(OCCULTO
        Cipher.cpp
        ImageHandler.cpp
        main.cpp
        Steganography.cpp
)

target_link_libraries(OCCULTO PRIVATE ${OpenCV_LIBS})

add_executable(tests
        test_main.cpp
        Cipher.cpp
        ImageHandler.cpp
        Steganography.cpp
)

target_link_libraries(tests PRIVATE gtest gtest_main ${OpenCV_LIBS})
