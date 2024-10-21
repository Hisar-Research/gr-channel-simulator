# CMake generated Testfile for 
# Source directory: /home/user/Masaüstü/gr-channel_simulator/python/channel_simulator
# Build directory: /home/user/Masaüstü/gr-channel_simulator/build/python/channel_simulator
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(qa_channelModel "/usr/bin/sh" "qa_channelModel_test.sh")
set_tests_properties(qa_channelModel PROPERTIES  _BACKTRACE_TRIPLES "/usr/lib/x86_64-linux-gnu/cmake/gnuradio/GrTest.cmake;119;add_test;/home/user/Masaüstü/gr-channel_simulator/python/channel_simulator/CMakeLists.txt;42;GR_ADD_TEST;/home/user/Masaüstü/gr-channel_simulator/python/channel_simulator/CMakeLists.txt;0;")
subdirs("bindings")
