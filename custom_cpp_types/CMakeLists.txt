########################################################################
# Project setup
########################################################################
cmake_minimum_required(VERSION 2.8.9)
project(CustomCppTypes CXX)

find_package(Pothos CONFIG REQUIRED)

########################################################################
# Build module
########################################################################
POTHOS_MODULE_UTIL(
    TARGET CustomCppTypes
    SOURCES
        FluffyData.cpp
    DESTINATION demos
    #ENABLE_DOCS
)
