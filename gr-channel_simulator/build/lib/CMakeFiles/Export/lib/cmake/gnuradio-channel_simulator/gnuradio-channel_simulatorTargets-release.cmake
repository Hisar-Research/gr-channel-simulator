#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "gnuradio::gnuradio-channel_simulator" for configuration "Release"
set_property(TARGET gnuradio::gnuradio-channel_simulator APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gnuradio::gnuradio-channel_simulator PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/x86_64-linux-gnu/libgnuradio-channel_simulator.so.1.0.0.0"
  IMPORTED_SONAME_RELEASE "libgnuradio-channel_simulator.so.1.0.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS gnuradio::gnuradio-channel_simulator )
list(APPEND _IMPORT_CHECK_FILES_FOR_gnuradio::gnuradio-channel_simulator "${_IMPORT_PREFIX}/lib/x86_64-linux-gnu/libgnuradio-channel_simulator.so.1.0.0.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
