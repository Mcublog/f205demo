function(LOG_INFO text)
    message("[INFO] " ${ARGV})
endfunction()

function(LOG_DEBUG text)
    message("[DEBUG] " ${ARGV})
endfunction()

function(LOG_WARN text)
    message("[WARN] " ${ARGV})
endfunction()

function(build_jlink_script target)
    add_custom_command(TARGET ${target}
        POST_BUILD
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy
        ARGS ${target}.hex ${PROJECT_SOURCE_DIR}/build/output/${target}.hex)

    configure_file(${PROJECT_SOURCE_DIR}/config/burn.jlink.in
        ${CMAKE_CURRENT_BINARY_DIR}/${target}.jlink
        ESCAPE_QUOTES)
endfunction()