cmake_minimum_required(VERSION 3.8)
project(test_node)

find_package(ament_cmake REQUIRED)
find_package(test_lib REQUIRED)
find_package(rclcpp REQUIRED)

add_executable(${PROJECT_NAME} src/node.cpp)
ament_target_dependencies(${PROJECT_NAME} test_lib rclcpp)

install(
  TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}Targets
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

ament_package()
