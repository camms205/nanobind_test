#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/tensor.h>
#include "lib.hpp"
#include <iostream>

namespace nb = nanobind;
using namespace nb::literals;

int add(int i, int j) {
    return i + j;
}

NB_MODULE(mymodule, m) {
    m.def("add", &add, "doc");
    m.def("test", [](int i) { return i; }, "a test function that prints integer", "i"_a);
    m.def("hello", &hello_world);
    m.def("one", &one);
    m.def("vec", []() {
        size_t shape[1] = {2};
        Eigen::Vector2f *v  = new Eigen::Vector2f(1, 2);
        nb::capsule deleter(v, [](void *data) noexcept {
           delete (Eigen::Vector2f *) data;
        });
        return nb::tensor<nb::numpy, float>(v->data(), 1, shape, deleter);
    });
    m.def("vec2", [](int x, int y) {
        Eigen::VectorXi *v = new Eigen::VectorXi(2);
        *v << x, y;
        nb::capsule deleter(v, [](void *data) noexcept {
           delete (Eigen::Vector2f *) data;
        });
        return nb::tensor<nb::numpy, int>(v->data(), 1, new size_t[1]{2}, deleter);
    });

    m.def("ret_numpy", []() {
        int *data = new int[8]{ 1, 2, 3, 4, 5, 6, 7, 8 };
        size_t shape[2] = { 2, 4 };
        nb::capsule deleter(data, [](void *data) noexcept {
           delete[] (int *) data;
        });
        return nb::tensor<nb::numpy, int, nb::shape<2, nb::any>>(
            data, 2, shape, deleter);
    });

    nb::class_<Pet>(m, "Pet")
        .def(nb::init<const std::string &>(), "name"_a)
        .def("setName", &Pet::setName, "name"_a)
        .def("getName", &Pet::getName)
        .def("__repr__", [](const Pet &a) {
            return "<Pet named '" + a.name + "'>";
        });
}