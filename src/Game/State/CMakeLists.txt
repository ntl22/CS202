target_sources(${APP_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/loading.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/loadingtask.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/menu.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/playing.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/levelup.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/save.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/pause.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/load.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/finish.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/save.cpp"
)

target_include_directories(${APP_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
