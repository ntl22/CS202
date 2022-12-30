target_sources(${APP_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/entity.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/obstacle.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/people.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/animal.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/animal.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/vehicle.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/vehicle.cpp"
    
)

target_include_directories(${APP_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
