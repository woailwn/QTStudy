# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\IDentiFy_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\IDentiFy_autogen.dir\\ParseCache.txt"
  "IDentiFy_autogen"
  )
endif()
