cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

set(PROJECT_NAME "Todo_JSON")
set(EXTERNAL_LIBS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external-libs")
set(PATH_TO_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/")

project(${PROJECT_NAME})

include(FetchContent)

FetchContent_Declare(json
    GIT_REPOSITORY https://github.com/nlohmann/json
    GIT_TAG v3.11.3
    SOURCE_DIR ${EXTERNAL_LIBS_DIR}/json
)
FetchContent_MakeAvailable(json)
#configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/tasks.json ${CMAKE_CURRENT_BINARY_DIR}/src/tasks.json COPYONLY)

set(INTERFACE_FILES
  ${PATH_TO_FILES}/headers/interfaces/ITaskManager.hpp
)


set(HEADER_FILES
  ${PATH_TO_FILES}/headers/TaskManager.hpp
)

set(SOURCE_FILES
  ${PATH_TO_FILES}/TaskManager.cpp
  ${PATH_TO_FILES}/app.cpp
)

add_executable(
  ${PROJECT_NAME}
  ${INTERFACE_FILES}
  ${HEADER_FILES}
  ${SOURCE_FILES}
)

target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE
  nlohmann_json::nlohmann_json
)

set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
)
