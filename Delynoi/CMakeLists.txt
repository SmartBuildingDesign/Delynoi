if(TARGET Delynoi)
    return()
endif()

file(GLOB_RECURSE SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.c)
file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_subdirectory(include/Delynoi/voronoi/lib)
add_subdirectory(lib/utilities)
add_library(Delynoi STATIC ${SRCS} ${HEADERS})

# Define headers for this library. PUBLIC headers are used for
# compiling the library, and will be added to consumers' build
# paths
target_include_directories(Delynoi PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE src)

# Depend on a library that we defined in the top-level file
target_link_libraries(Delynoi Delynoi_triangle Delynoi_utilities)

# 'make install' to the correct locations (provided by GNUInstallDirs)
install(TARGETS Delynoi EXPORT DelynoiConfig
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}) # This is for Windows
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# This makes the project importable from the install directory
# Put config file in per-project dir (name MUST match), can also
# just go into 'cmake'
install(EXPORT DelynoiConfig DESTINATION share/DelynoiConfig/cmake)

# This makes the project importable from the build directory
export(TARGETS Delynoi FILE DelynoiConfig.cmake)