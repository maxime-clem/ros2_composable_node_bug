cmake_minimum_required(VERSION 3.8)
project(test_composable_node)

find_package(ament_cmake REQUIRED)

find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(test_lib REQUIRED)
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)

add_library(${PROJECT_NAME} SHARED src/node.cpp)
target_compile_definitions(${PROJECT_NAME}
  PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(${PROJECT_NAME} rclcpp rclcpp_components test_lib)
rclcpp_components_register_node(${PROJECT_NAME}
  PLUGIN "TestComposableNode"
  EXECUTABLE ${PROJECT_NAME}_exe
)

install(
  TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

ament_package()
