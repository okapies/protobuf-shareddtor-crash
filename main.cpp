#include <string>
#include <iostream>

#include "foo.hpp"
#include "onnx/onnx.pb.h"

int main() {
    std::cout << "# Invoking: foo::new_onnx_model()" << std::endl;
    onnx::ModelProto model = foo::new_onnx_model();
    std::cout << "# Finished: foo::new_onnx_model() (onnx::ModelProto is " << std::hex << &model << ")" << std::endl;

    std::cout << "producer_name: " << model.producer_name() << std::endl;

    return 0;
}
