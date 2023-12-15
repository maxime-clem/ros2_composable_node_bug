#include "rclcpp/rclcpp.hpp"
#include "test_lib/lib.hpp"

#include <memory>
#include <string>

class TestNode : public rclcpp::Node
{
public:
  TestNode() : Node("test_node") {
    print_in_python_interpreter();
    import_pytorch_in_python_interpreter();
  }
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TestNode>());
  rclcpp::shutdown();
  return 0;
}
