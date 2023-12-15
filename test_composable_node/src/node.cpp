#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/register_node_macro.hpp"

#include <test_lib/lib.hpp>

#include <memory>
#include <string>

class TestComposableNode : public rclcpp::Node
{
public:
  TestComposableNode(const rclcpp::NodeOptions & options) : Node("test_composable_node", options)
  {
    print_in_python_interpreter();
    import_pytorch_in_python_interpreter();
  }
};

RCLCPP_COMPONENTS_REGISTER_NODE(TestComposableNode)
