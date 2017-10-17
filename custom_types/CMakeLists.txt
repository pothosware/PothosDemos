########################################################################
# Project setup
########################################################################
cmake_minimum_required(VERSION 2.8.9)
project(CustomTypes CXX)

find_package(Pothos "0.6.0" CONFIG REQUIRED)
include(PothosPythonUtil)

########################################################################
# C++ type library
########################################################################
include_directories(${Pothos_INCLUDE_DIRS})
add_library(FluffyData SHARED FluffyData.cpp)
target_link_libraries(FluffyData ${Pothos_LIBRARIES})
install(TARGETS FluffyData DESTINATION lib)

########################################################################
# C++ blocks
########################################################################
POTHOS_MODULE_UTIL(
    TARGET CustomTypesCpp
    SOURCES
        FluffySource.cpp
        FluffySource2.cpp
        FluffySink.cpp
        FluffySink2.cpp
        SpikeySource.cpp
        SpikeySink.cpp
    DESTINATION PothosDemos
    LIBRARIES FluffyData
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

########################################################################
# Remote executables
########################################################################
include_directories(${Pothos_INCLUDE_DIRS})
add_executable(FluffyRemote FluffyRemote.cpp)
target_link_libraries(FluffyRemote ${Pothos_LIBRARIES} FluffyData)
