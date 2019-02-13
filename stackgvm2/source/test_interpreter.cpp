/**
 * TOYTL - GVM
 *
 * Twenty Odd Years Too Late Game Virtual Machine
 */

#include <cstdio>
#include "include/gvm_core.hpp"
#include "include/gvm_codemacros.hpp"

using namespace GVM;

Result printInteger(Scalar* frame) {
    std::printf("HOST: printInteger() = %d\n", frame[0].i);
    return SUCCESS;
}

Result printFloat(Scalar* frame) {
    std::printf("HOST: printFloat() = %f\n", frame[0].f);
    return SUCCESS;
}

Result printVector(Scalar* frame) {
    std::printf("HOST: printVector() = { %f, %f, %f }\n", frame[0].f, frame[1].f, frame[2].f);
    return SUCCESS;
}

uint8 _gvm_test1[] = {
    add_lll (1, 2, 3)       // fs[3] = fs[1] + fs[2]
    call    (2)
    hcall   (1)            // Call host function (1)
    copy_ll (3, 0)         // fs[0] = fs[3]
    ret
};

uint8 _gvm_test2[] = {
    lsl_lll (0, 0, 0) // fs[0] = fs[1] << fs[1]
    ret
};


FuncInfo functionTable[] = {
    { 0, 0, 0, 0, 0 },           // index 0 must be null
    { _gvm_test1, 3, 1, 2, 0 },
    { _gvm_test2, 1, 1, 0, 0 },
    { 0, 0, 0, 0, 0 }            // Null termimated set
};

HostCall hostFunctionTable[] = {
    0,                           // Index 0 must be null
    printInteger,
    printFloat,
    0                            // Null terminated set
};

Scalar dummyVector[] = {
    0.25f,
    0.5f,
    0.75f
};

Scalar* globalData[] = {
    0,                           // Index 0 must be null
    dummyVector,
    0                            // Null terminated set
};

int main() {
    std::printf("Max Opcode %d\n", Opcode::_MAX);
    Interpreter::init(100, 0, functionTable, hostFunctionTable, globalData);
    Scalar* stack = Interpreter::stack();
    stack[0].i = 0;
    stack[1].i = 1;
    stack[2].i = 2;

    std::printf(
        "\nBefore\n\tstack[0] = %d\n\tstack[1] = %d\n\tstack[2] = %d\n",
        stack[0].i,
        stack[1].i,
        stack[2].i
    );

    Result result = Interpreter::invoke(1);

    std::printf(
        "\nAfter\n\tResult = %d\n\tstack[0] = %d\n\tstack[1] = %d\n\tstack[2] = %d\n",
        result,
        stack[0].i,
        stack[1].i,
        stack[2].i
    );

    Interpreter::done();

    return 0;
}
