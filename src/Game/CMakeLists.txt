target_sources(LIB PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/application.cpp"
)

target_include_directories(LIB PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(Entity)
add_subdirectory(State)
