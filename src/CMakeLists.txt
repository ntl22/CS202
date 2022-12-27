# add_library(LIB STATIC "")
# target_link_libraries(LIB PRIVATE sfml-graphics 
#                                   sfml-window 
#                                   sfml-system)
# add_subdirectory("Framework")
# add_subdirectory("Game")

if (WIN32)
    add_executable(road WIN32 main.cpp)
else()
    add_executable(road main.cpp)
endif()

target_link_libraries(road PRIVATE LIB sfml-graphics 
                                       sfml-window 
                                       sfml-system
                                       sfml-audio
                                       sfml-main)

if (WIN32)
    if (BUILD_SHARED_LIBS)
        add_custom_command(TARGET road POST_BUILD 
            COMMAND ${CMAKE_COMMAND} -E copy 
            $<TARGET_RUNTIME_DLLS:road> $<TARGET_FILE_DIR:road> COMMAND_EXPAND_LISTS)
    endif()

    if (CMAKE_SIZEOF_VOID_P EQUAL 8)
        add_custom_command(TARGET road POST_BUILD 
            COMMAND ${CMAKE_COMMAND} -E copy 
            ${FETCHCONTENT_BASE_DIR}/sfml-src/extlibs/bin/x64/openal32.dll
            $<TARGET_FILE_DIR:road>)
    elseif (CMAKE_SIZEOF_VOID_P EQUAL 4)
    add_custom_command(TARGET road POST_BUILD 
            COMMAND ${CMAKE_COMMAND} -E copy 
            ${FETCHCONTENT_BASE_DIR}/sfml-src/extlibs/bin/x86/openal32.dll
            $<TARGET_FILE_DIR:road>)
    endif()
endif()
