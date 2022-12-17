cmake_minimum_required(VERSION 3.22.0)
project(
	ACDC
		VERSION 0.1.0
		DESCRIPTION "Amazing Code Diff Comparator"
		LANGUAGES CXX
)

include(CTest)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

add_library(${PROJECT_NAME} STATIC)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)

target_include_directories(${PROJECT_NAME}
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# ACDC Tests

if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
	add_subdirectory(tests)
endif ()

enable_testing()
