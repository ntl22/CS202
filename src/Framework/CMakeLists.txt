add_subdirectory(Asset)
add_subdirectory(State)
add_subdirectory(Util)
add_subdirectory(Widget)

target_precompile_headers(${APP_NAME} PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}/pch.hpp")
