cmake_minimum_required(VERSION 3.16)

project(JCBC
  LANGUAGES C)

set(JCBC jcbc)

set(CMAKE_DISABLE_SOURCE_CHANGES  ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/static)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/dynamic)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if(NOT EXISTS "${CMAKE_SOURCE_DIR}/compile_commands.json")
  file(RELATIVE_PATH buildRelPath "${CMAKE_SOURCE_DIR}" "${CMAKE_BINARY_DIR}")
  execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink
    "${buildRelPath}/compile_commands.json"
    "${CMAKE_SOURCE_DIR}/compile_commands.json")
endif()

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS_DEBUG "-g -Wall -Wextra -pedantic")

include_directories(include/)
add_subdirectory(src/)


# WHY WOULD YOU WANT TO INSTALL THIS?! ----------------------------------------

include(GNUInstallDirs)
install(TARGETS "${JCBC}")
install(
  DIRECTORY "${PROJECT_SOURCE_DIR}/include/"
  DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
  FILES_MATCHING PATTERN "*.h"
  )
