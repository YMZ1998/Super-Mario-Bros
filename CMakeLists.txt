cmake_minimum_required(VERSION 3.11)
project(SuperMarioBros LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Use the prebuilt SFML package checked into the project under 3rdparty.
set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/SFML/lib/cmake/SFML"
    CACHE PATH "Path to the local SFML CMake package")
set(SFML_STATIC_LIBRARIES FALSE)
find_package(SFML 2.5 CONFIG REQUIRED COMPONENTS graphics window system)

# Collect source files
file(GLOB SOURCE_FILES "Source/*.cpp" "Source/*/*.hpp")

# Create executable
add_executable(mario ${SOURCE_FILES})

# Include directories
target_include_directories(mario PRIVATE "Source/Headers")
# Link SFML libraries
target_link_libraries(mario PRIVATE sfml-graphics sfml-window sfml-system)

# Copy game resources and SFML runtime libraries next to the executable.
file(COPY "Source/Resources" DESTINATION ${CMAKE_BINARY_DIR})
add_custom_command(TARGET mario POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
          "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/SFML/bin"
          "$<TARGET_FILE_DIR:mario>"
)
