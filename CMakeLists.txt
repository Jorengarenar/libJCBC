cmake_minimum_required(VERSION 3.16)

project(JCBC
  VERSION 0.1.0
  LANGUAGES C)

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

set(ONLY_DOCS NO CACHE BOOL "Whether to build only docs")

if(NOT ONLY_DOCS)

  include_directories(include/)

  add_subdirectory(src/)

  include(CTest)
  #add_subdirectory(tests/)

endif()

add_subdirectory(docs/)

include(GNUInstallDirs)

configure_file("${PROJECT_SOURCE_DIR}/libjcbc.pc.in"
               "${PROJECT_BINARY_DIR}/libjcbc.pc" @ONLY)

install(TARGETS "${PROJECT_NAME}")

install(
  DIRECTORY "${PROJECT_SOURCE_DIR}/include/"
  DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
  FILES_MATCHING PATTERN "*.h"
  )
