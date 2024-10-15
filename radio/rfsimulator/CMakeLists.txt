add_library(rfsimulator MODULE
            simulator.c
            apply_channelmod.c
            ../../openair1/PHY/TOOLS/signal_energy.c
)

set(ZMQ_INCLUDE_DIR "/usr/local/include")
set(ZMQ_LIBRARY "/usr/local/lib/libzmq.so")
include_directories(${ZMQ_INCLUDE_DIR})
target_link_libraries(rfsimulator PRIVATE SIMU ${ZMQ_LIBRARY})
set_target_properties(rfsimulator PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_executable(replay_node stored_node.c)
target_link_libraries (replay_node minimal_lib)
