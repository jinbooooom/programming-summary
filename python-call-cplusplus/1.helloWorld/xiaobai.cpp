#include <iostream>
#include <pybind11/pybind11.h>

namespace py = pybind11;

int add(int i, int j)
{
    return i + j;
}

void helloWorld()
{
    std::cout << "Hello World!" << std::endl;
}

PYBIND11_MODULE(xiaobai, m)
{
    m.doc() = "pybind11 example plugin";  // optional module docstring
    m.def("add", &add, "A function which adds two numbers");
    m.def("helloWorld", &helloWorld, "Print hello world");
}