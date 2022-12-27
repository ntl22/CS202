target_sources(LIB PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/pch.hpp"
)

target_include_directories(LIB PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(Asset)
add_subdirectory(State)
add_subdirectory(Util)
add_subdirectory(Widget)
