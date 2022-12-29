if (WIN32)
    add_executable(${APP_NAME} WIN32 main.cpp)
else()
    add_executable(${APP_NAME} main.cpp)
endif()

add_subdirectory(Framework)
add_subdirectory(Game)

target_link_libraries(${APP_NAME} PRIVATE sfml-graphics 
                                          sfml-window 
                                          sfml-system
                                          sfml-audio
                                          sfml-main)

add_custom_command(TARGET ${APP_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${APP_NAME}>/assets)

if (WIN32)
    if (BUILD_SHARED_LIBS)
        add_custom_command(TARGET ${APP_NAME} POST_BUILD 
            COMMAND ${CMAKE_COMMAND} -E copy 
            $<TARGET_RUNTIME_DLLS:${APP_NAME}> $<TARGET_FILE_DIR:${APP_NAME}> COMMAND_EXPAND_LISTS)
    endif()

    if (CMAKE_SIZEOF_VOID_P EQUAL 8)
        add_custom_command(TARGET ${APP_NAME} POST_BUILD 
            COMMAND ${CMAKE_COMMAND} -E copy 
            ${FETCHCONTENT_BASE_DIR}/sfml-src/extlibs/bin/x64/openal32.dll
            $<TARGET_FILE_DIR:${APP_NAME}>)
    elseif (CMAKE_SIZEOF_VOID_P EQUAL 4)
    add_custom_command(TARGET ${APP_NAME} POST_BUILD 
            COMMAND ${CMAKE_COMMAND} -E copy 
            ${FETCHCONTENT_BASE_DIR}/sfml-src/extlibs/bin/x86/openal32.dll
            $<TARGET_FILE_DIR:${APP_NAME}>)
    endif()
endif()
