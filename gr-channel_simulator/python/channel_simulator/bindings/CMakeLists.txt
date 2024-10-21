# Copyright 2020 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

########################################################################
# Check if there is C++ code at all
########################################################################
if(NOT channel_simulator_sources)
    MESSAGE(STATUS "No C++ sources... skipping python bindings")
    return()
endif(NOT channel_simulator_sources)

########################################################################
# Check for pygccxml
########################################################################
GR_PYTHON_CHECK_MODULE_RAW(
    "pygccxml"
    "import pygccxml"
    PYGCCXML_FOUND
    )

include(GrPybind)

########################################################################
# Python Bindings
########################################################################

list(APPEND channel_simulator_python_files
    channelModel_python.cc python_bindings.cc)

GR_PYBIND_MAKE_OOT(channel_simulator
   ../../..
   gr::channel_simulator
   "${channel_simulator_python_files}")

# copy bindings extension for use in QA test module
add_custom_command(TARGET channel_simulator_python POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:channel_simulator_python>
    ${PROJECT_BINARY_DIR}/test_modules/gnuradio/channel_simulator/
)

install(TARGETS channel_simulator_python DESTINATION ${GR_PYTHON_DIR}/gnuradio/channel_simulator COMPONENT pythonapi)
