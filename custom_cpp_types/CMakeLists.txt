########################################################################
# Project setup
########################################################################
cmake_minimum_required(VERSION 2.8.9)
project(CustomCppTypes CXX)

find_package(Pothos CONFIG REQUIRED)
include(PothosPythonUtil)

########################################################################
# C++ blocks + type
########################################################################
POTHOS_MODULE_UTIL(
    TARGET CustomCppTypes
    SOURCES
        FluffyData.cpp
        FluffySource1.cpp
        FluffySource2.cpp
        FluffySink1.cpp
        FluffySink2.cpp
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
    FACTORIES
        "/demos/fluffy_source_py:FluffySource"
        "/demos/fluffy_sink_py:FluffySink"
    DESTINATION PothosDemos
    #ENABLE_DOCS
)
