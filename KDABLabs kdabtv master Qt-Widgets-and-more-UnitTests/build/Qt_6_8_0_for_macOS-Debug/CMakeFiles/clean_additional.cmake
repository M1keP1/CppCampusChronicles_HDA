# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/CalculatorApp_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/CalculatorApp_autogen.dir/ParseCache.txt"
  "CMakeFiles/CalculatorLib_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/CalculatorLib_autogen.dir/ParseCache.txt"
  "CalculatorApp_autogen"
  "CalculatorLib_autogen"
  "Tests/CMakeFiles/basics_autogen.dir/AutogenUsed.txt"
  "Tests/CMakeFiles/basics_autogen.dir/ParseCache.txt"
  "Tests/basics_autogen"
  )
endif()
