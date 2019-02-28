/**
 * TOYTL - GVM
 *
 * Twenty Odd Years Too Late Game Virtual Machine
 */

#include <cstdio>
#include "include/gvm_opcode.hpp"

using namespace GVM;

int main() {
    std::fprintf(stderr, "Max Opcode %d\n", Opcode::_MAX_OPCODE);
    return 0;
}
