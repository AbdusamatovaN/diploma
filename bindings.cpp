// bindings.cpp
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "sign.h"

namespace py = pybind11;

PYBIND11_MODULE(sign_module, m) {
    py::class_<Coordinates>(m, "Coordinates")
        .def(py::init<>())
        .def_readwrite("longitude", &Coordinates::longitude)
        .def_readwrite("latitude", &Coordinates::latitude);

    py::class_<Sign>(m, "Sign")
        .def(py::init<const std::string&, unsigned int, const Coordinates&>())
        .def_readwrite("name", &Sign::name)
        .def_readwrite("id", &Sign::id)
        .def_readwrite("coordinates", &Sign::coordinates);

    py::class_<SignDatabase>(m, "SignDatabase")
        .def(py::init<>())
        .def("add_sign", &SignDatabase::addSign)
        .def("remove_sign", &SignDatabase::removeSign)
        .def("find_sign", &SignDatabase::findSign)
        .def("add_signs", &SignDatabase::addSigns);
}
