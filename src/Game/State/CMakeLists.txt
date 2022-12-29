target_sources(${APP_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/menu.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/splash.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/playing.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/pause.cpp"
)

target_include_directories(${APP_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
