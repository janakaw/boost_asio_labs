cmake_minimum_required (VERSION 2.6)

project (Test)

## Set version number
set (VERSION_MAJOR 0)
set (VERSION_MINOR 1)

#set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

## add system introspection
# does this system has a log function
#include (checkFunctionExists)
#check_function_exits (log HAVE_LOG)


## switch between libraries
option (MYSQRT "use custom sqrt" ON)



# configure a header file to pass CMake settings 
# to source
configure_file (
  "${PROJECT_SOURCE_DIR}/config/config.h.in"
  "${PROJECT_BINARY_DIR}/config/config.h"
)

# add binary tree config dir in include search path
include_directories ("${PROJECT_BINARY_DIR}/config")


## add lib
add_subdirectory (lib)

if (MYSQRT)
  include_directories ( "${PROJECT_SOURCE_DIR}/lib" )
  set (OTHER_LIBS ${OTHER_LIBS} mysqrt)
endif (MYSQRT)

# add executable
add_executable (example example.cpp)
target_link_libraries (example ${OTHER_LIBS})


## add install targets
set (CMAKE_INSTALL_PREFIX "/tmp/cmake_test")

install (TARGETS example DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/config/config.h" DESTINATION include)


## run tests 
include (CTest)

add_test (examplerun example)

add_test (exampleOutputTest example)
set_tests_properties (exampleOutputTest PROPERTIES PASS_REGULAR_EXPRESSION "2.5")
