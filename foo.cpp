#include <iostream>

#include "onnx/onnx.pb.h"

#ifdef __cplusplus
namespace foo
{
#endif

onnx::ModelProto new_onnx_model() {
    std::cout << "## Starting: onnx::ModelProto::new_onnx_model()" << std::endl;
    onnx::ModelProto model;
    std::cout << "## GetEmptyStringAlreadyInited in libfoo.so is " << std::hex << &::google::protobuf::internal::GetEmptyStringAlreadyInited() << std::endl;
    std::cout << "## Finishing: onnx::ModelProto::new_onnx_model() (returns " << std::hex << &model << ")" << std::endl;
    return model;
}

#ifdef __cplusplus
}
#endif
