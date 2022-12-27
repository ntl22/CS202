target_sources(LIB PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/center.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/context.cpp"
)

target_include_directories(LIB PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")