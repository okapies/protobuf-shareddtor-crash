#include <iostream>

#include "onnx/onnx.pb.h"

#ifdef __cplusplus
namespace foo
{
#endif

onnx::ModelProto new_onnx_model() {
    std::cout << "## Starting: onnx::ModelProto::new_onnx_model()" << std::endl;
    onnx::ModelProto model;
    std::cout << "## Finishing: onnx::ModelProto::new_onnx_model() (onnx::ModelProto is " << std::hex << &model << ")" << std::endl;
    std::cout << "## GetEmptyStringAlreadyInited in libfoo.so is " << std::hex << &::google::protobuf::internal::GetEmptyStringAlreadyInited() << std::endl;
    return model;
}

#ifdef __cplusplus
}
#endif
