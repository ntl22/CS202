target_sources(${APP_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/obstacle.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/player.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/animal.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/vehicle.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/f_obstacle.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/road.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/f_road.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/timer.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/light.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/world.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/player.cpp"
)

target_include_directories(${APP_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
