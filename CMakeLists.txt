cmake_minimum_required(VERSION 3.18)

project(PathFinder-001)

add_library(PathFinder
    libpathfinder/src/Position.hpp
    libpathfinder/src/Position.cpp
    libpathfinder/src/Matrix.hpp
    libpathfinder/src/Matrix.cpp
    libpathfinder/src/Sequence.hpp
    libpathfinder/src/Sequence.cpp
    libpathfinder/src/PathFinder.hpp
    libpathfinder/src/PathFinder.cpp
)

add_library(PathFinderImpl
    libpathfinderimpl/src/ReCurPathFinder.hpp
    libpathfinderimpl/src/ReCurPathFinder.cpp
)

add_library(PathFinderImpl2
    libpathfinderimpl2/src/BTPathFinder.hpp
    libpathfinderimpl2/src/BTPathFinder.cpp
)

add_library(Examples
    libexamples/src/Examples.hpp
    libexamples/src/Examples.cpp
)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(PathFinder PUBLIC /W3 /MP /permissive-)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(PathFinder PUBLIC -Wall -fpermissive)
else()
    target_compile_options(PathFinder PUBLIC -Wall)
endif()

target_compile_features(PathFinderImpl PUBLIC cxx_std_17)
target_include_directories(PathFinderImpl PUBLIC libpathfinder/src PUBLIC libpathfinderimpl/src)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(PathFinderImpl PUBLIC /W3 /MP /permissive-)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(PathFinderImpl PUBLIC -Wall -fpermissive)
else()
    target_compile_options(PathFinderImpl PUBLIC -Wall)
endif()

target_compile_features(PathFinderImpl2 PUBLIC cxx_std_17)
target_include_directories(PathFinderImpl2 PUBLIC libpathfinder/src PUBLIC libpathfinderimpl2/src)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(PathFinderImpl2 PUBLIC /W3 /MP /permissive-)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(PathFinderImpl2 PUBLIC -Wall -fpermissive)
else()
    target_compile_options(PathFinderImpl2 PUBLIC -Wall)
endif()

target_compile_features(Examples PUBLIC cxx_std_17)
target_include_directories(Examples PUBLIC libpathfinder/src PUBLIC libexamples/src)


add_executable(ReCurPathFinderTest
    pathfindertests/src/ReCurPathFinderTest.cpp
)

target_link_libraries(ReCurPathFinderTest PRIVATE Examples PRIVATE PathFinderImpl PRIVATE PathFinder)
set_target_properties(ReCurPathFinderTest PROPERTIES RUNTIME_OUTPUT_NAME "ReCurPathFinderTest")
target_include_directories(ReCurPathFinderTest PUBLIC libpathfinder/src PUBLIC libexamples/src)

add_executable(BTPathFinderTest
    pathfindertests/src/BTPathFinderTest.cpp
)

target_link_libraries(BTPathFinderTest PRIVATE Examples PRIVATE PathFinderImpl2 PRIVATE PathFinder)
set_target_properties(BTPathFinderTest PROPERTIES RUNTIME_OUTPUT_NAME "BTPathFinderTest")
target_include_directories(ReCurPathFinderTest PUBLIC libpathfinder/src PUBLIC libexamples/src)

add_executable(PathFinderTest
    pathfindertests/src/PathFinderTest.cpp
)

target_link_libraries(PathFinderTest PRIVATE Examples PRIVATE PathFinderImpl PRIVATE PathFinder)
set_target_properties(PathFinderTest PROPERTIES RUNTIME_OUTPUT_NAME "PathFinderTest")
target_include_directories(PathFinderTest PUBLIC libpathfinder/src PUBLIC libexamples/src)
