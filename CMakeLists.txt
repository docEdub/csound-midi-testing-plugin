# CMake 3.24 is required for CMAKE_PROJECT_TOP_LEVEL_INCLUDES used in CMakeCsoundPlugin.
cmake_minimum_required(VERSION 3.24)

set(NO_VCPKG ON)

include("cmake/fetch_dependency.cmake")

fetch_dependency(
    NAME CMakeCsoundPlugin
    URL https://github.com/docEdub/CMakeCsoundPlugin/archive/refs/tags/2024.01.24.tar.gz
    URL_MD5 6db9d32a344106100acb93be26dd3fa2
)

project(csound-midi-testing-plugin)

add_csound_plugin(
    TARGET midi-testing
    SOURCES
        "src/_init_.c"
        "src/common.c"
        "src/common.h"
        "src/noteOn.c"
        "src/noteOn.h"
        "src/noteOff.c"
        "src/noteOff.h"
)
