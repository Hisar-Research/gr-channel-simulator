find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_CHANNEL_SIMULATOR gnuradio-channel_simulator)

FIND_PATH(
    GR_CHANNEL_SIMULATOR_INCLUDE_DIRS
    NAMES gnuradio/channel_simulator/api.h
    HINTS $ENV{CHANNEL_SIMULATOR_DIR}/include
        ${PC_CHANNEL_SIMULATOR_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_CHANNEL_SIMULATOR_LIBRARIES
    NAMES gnuradio-channel_simulator
    HINTS $ENV{CHANNEL_SIMULATOR_DIR}/lib
        ${PC_CHANNEL_SIMULATOR_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-channel_simulatorTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_CHANNEL_SIMULATOR DEFAULT_MSG GR_CHANNEL_SIMULATOR_LIBRARIES GR_CHANNEL_SIMULATOR_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_CHANNEL_SIMULATOR_LIBRARIES GR_CHANNEL_SIMULATOR_INCLUDE_DIRS)
