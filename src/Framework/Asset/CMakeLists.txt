target_sources(${APP_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/manager.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/music.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/sound.cpp"
)

target_include_directories(${APP_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
