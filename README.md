# Composable node issue with libpython

## Repository description

This repository contains 4 packages.
###  `test_lib`
Library package with 2 functions.
- `print_in_python_interpreter()`: print to stdout using the python interpreter.
- `import_pytorch_in_python_interpreter()`: import the `torch` library using the python interpreter.

### `test_exe`
Package generating one executable which calls the 2 functions.

### `test_node`
Package with a node that calls the 2 functions in its constructor.

### `test_composable_node`
Package with a composable node that calls the 2 functions in its constructor.

## How to reproduce the issue

```
colcon build
source install/setup.sh
ros2 run test_exe test_exe  # No issue
ros2 run test_node test_node  # No issue
ros2 run test_composable_node test_composable_node_exe  # undefined symbol error
```

For some reason, the composable node fails to execute the `import_pytorch_in_python_interpreter()` function (no issue with the other function).

Output
```
print: OK
terminate called after throwing an instance of 'pybind11::error_already_set'
  what():  ImportError: /usr/lib/python3.10/lib-dynload/_ctypes.cpython-310-x86_64-linux-gnu.so: undefined symbol: PyTuple_Type

At:
  /usr/lib/python3.10/ctypes/__init__.py(8): <module>
  <frozen importlib._bootstrap>(241): _call_with_frames_removed
  <frozen importlib._bootstrap_external>(883): exec_module
  <frozen importlib._bootstrap>(703): _load_unlocked
  <frozen importlib._bootstrap>(1006): _find_and_load_unlocked
  <frozen importlib._bootstrap>(1027): _find_and_load
  /home/mclement/.local/lib/python3.10/site-packages/torch/__init__.py(17): <module>
  <frozen importlib._bootstrap>(241): _call_with_frames_removed
  <frozen importlib._bootstrap_external>(883): exec_module
  <frozen importlib._bootstrap>(703): _load_unlocked
  <frozen importlib._bootstrap>(1006): _find_and_load_unlocked
  <frozen importlib._bootstrap>(1027): _find_and_load
```

Expected output
```
print: OK
import torch: OK
```

## Workaround

The only workaround found so far is to use `dlopen("libpython3.10.so", RTLD_GLOBAL | RTLD_NOW)` in the composable node code to manually load the library at runtime.