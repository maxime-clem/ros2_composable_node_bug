cmake_minimum_required(VERSION 3.8)
project(test_lib)

find_package(ament_cmake REQUIRED)
find_package(pybind11 REQUIRED)
find_package(Python3 COMPONENTS Interpreter Development)

add_library(${PROJECT_NAME} SHARED src/lib.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${Python3_INCLUDE_DIRS}
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
ament_target_dependencies(${PROJECT_NAME} pybind11 Python3)

ament_export_targets(${PROJECT_NAME}Targets HAS_LIBRARY_TARGET)
ament_export_dependencies(pybind11 Python3)

install(
  DIRECTORY include/
  DESTINATION include
)

install(
  TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}Targets
  LIBRARY DESTINATION lib
  INCLUDES DESTINATION include
)

ament_package()
