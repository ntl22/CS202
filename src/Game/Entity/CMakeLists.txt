target_sources(${APP_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/collidable.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/light.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/player.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/road.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/timer.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/world.cpp"
)

target_include_directories(${APP_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
