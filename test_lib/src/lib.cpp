#include "test_lib/lib.hpp"

#include <pybind11/embed.h>

#include <iostream>

namespace py = pybind11;

void print_in_python_interpreter()
{
  py::scoped_interpreter guard{};
  py::print("print: OK");
}

void import_pytorch_in_python_interpreter()
{
  py::scoped_interpreter guard{};
  py::module_ torch = py::module_::import("torch");
  std::cout << "import torch: OK" << std::endl;
}
