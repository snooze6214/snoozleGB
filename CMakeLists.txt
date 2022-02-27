# CMakeList.txt : CMake project for snoozleGB, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("snoozleGB")

# Dependencies
find_package(glfw3 REQUIRED)
find_package(imgui REQUIRED)
find_package(spdlog REQUIRED)

# Add source to this project's executable.
add_executable (snoozleGB "main.cpp"  "snoozlegb.h" "snoozlegb.cpp" "gui.h" "gui.cpp" "logging.h" "logging.cpp")

target_include_directories(snoozleGB 
  PRIVATE 
    "${CMAKE_CURRENT_LIST_DIR}"
)

target_link_libraries(
  snoozleGB
  PRIVATE
    opengl32
    glfw
    spdlog::spdlog_header_only
    imgui::imgui
)

set_property(TARGET snoozleGB
    PROPERTY
        CXX_STANDARD 17
)
