#include <pybind11/pybind11.h>
#include <iostream>

namespace py = pybind11;

void blockchain() {
    std::cout << "Ecce Blockchain";    
}

PYBIND11_MODULE(main, handle) {
    handle.def("blockchain", &blockchain);
}
