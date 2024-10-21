#!/usr/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/user/Masaüstü/gr-channel_simulator/python/channel_simulator
export GR_CONF_CONTROLPORT_ON=False
export PATH="/home/user/Masaüstü/gr-channel_simulator/build/python/channel_simulator":"$PATH"
export LD_LIBRARY_PATH="":$LD_LIBRARY_PATH
export PYTHONPATH=/home/user/Masaüstü/gr-channel_simulator/build/test_modules:$PYTHONPATH
/usr/bin/python3 /home/user/Masaüstü/gr-channel_simulator/python/channel_simulator/qa_channelModel.py 
