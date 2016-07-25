########################################################################
# Project setup
########################################################################
cmake_minimum_required(VERSION 2.8.9)
project(CustomTypes CXX)

find_package(Pothos CONFIG REQUIRED)
include(PothosPythonUtil)

########################################################################
# C++ blocks + type
########################################################################
POTHOS_MODULE_UTIL(
    TARGET CustomTypesCpp
    SOURCES
        FluffyData.cpp
        FluffySource1.cpp
        FluffySource2.cpp
        FluffySink1.cpp
        FluffySink2.cpp
        SpikeySource.cpp
        SpikeySink.cpp
    DESTINATION PothosDemos
    #ENABLE_DOCS
)

########################################################################
# Python blocks
########################################################################
POTHOS_PYTHON_UTIL(
    TARGET CustomTypesPython
    SOURCES
        __init__.py
        FluffySource.py
        FluffySink.py
        SpikeySource.py
        SpikeySink.py
        SpikeyData.py
    FACTORIES
        "/demos/fluffy_source_py:FluffySource"
        "/demos/fluffy_sink_py:FluffySink"
        "/demos/spikey_source_py:SpikeySource"
        "/demos/spikey_sink_py:SpikeySink"
    DESTINATION PothosDemosCustomTypes
    #ENABLE_DOCS
)
