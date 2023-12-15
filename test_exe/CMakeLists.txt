cmake_minimum_required(VERSION 3.8)
project(test_exe)

find_package(ament_cmake REQUIRED)
find_package(test_lib REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)
ament_target_dependencies(${PROJECT_NAME} test_lib)

install(
  TARGETS ${PROJECT_NAME}
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

ament_package()
