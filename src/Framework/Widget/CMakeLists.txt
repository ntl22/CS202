target_sources(LIB PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/widget.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/button.cpp"
)

target_include_directories(LIB PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")