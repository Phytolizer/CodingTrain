function(coding_challenge)
    cmake_parse_arguments(PARSE_ARGV 0 "CC" "" "NAME" "SOURCES;DEPENDS")
    if(NOT CC_NAME)
        message(FATAL_ERROR "No challenge name specified")
    endif()

    if(NOT CC_SOURCES)
        message(FATAL_ERROR "No sources specified")
    endif()

    add_executable(${CC_NAME} ${CC_SOURCES})
    target_compile_features(${CC_NAME} PRIVATE cxx_std_20)
    target_link_libraries(
        ${CC_NAME} PRIVATE cpprocessing::cpprocessing sfml-graphics sfml-system
                           sfml-window ${CC_DEPENDS}
    )
endfunction()

add_subdirectory("c001_starfield")
