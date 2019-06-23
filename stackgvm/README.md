# TOYTL StackGVM

A 32-bit pure VM intended for use within the TOYTL Engine. This provides support for 32-bit integer, floating point and vector operations where a vector is defined as a triplet of 3 floating point values.
- Note: 64-bit is now supported as an experiment and is not yet compatible with code created for 32-bit targets.
- Instructions are implemented as pure byte code comprising of between 1 to 6 bytes typically.
- Instructions have up to three operands. Generally all dyadic operations have 3, two source operands and a destination.
- 16-bit values may be used for branch targets and identifiers for function IDs, global data references etc. Where these are present in the byte code, they are stored MSB first.

The implementation is not instanced. A single static class forms the basis of the interpreter. This is a deliberate choice as there is no use case within the TOYTL Engine for more than one instance and removing the hidden indirection improves performance.

The implementation is neither a register machine or a pure stack machine. Instead, a stack frame model is used in which every function defines a stack frame that gives each invocation of that function the space required for it's return, parameters and any local temporaries. Instructions operating on the stack frame interpret their operands as offsets.

Since only 32-bit scalar types are supported, the machine allows indirection. Every frame has a pair of indirection pointers that can be assigned an address, permitting instructions that support indirection to do operate directly on the target data.

# Compilation Flags
- `_GVM_HOST_OS_` Specifies which host operating system the interpreter is being built for. This is in the absence of being built as part of an actual engine project. Targets are defined in include/host_machine.hpp
- `_GVM_OPT_CACHE_POINTERS_` Assigns the program counter, stack frame and indirection pointers to local variables within the main switch/case interpreter loop, only writing them back to the Interpreter state when necessary. This reduces the amount of code the compiler has to emit.
- `_GVM_OPT_ALLOW_GOTO_` Enables the use of goto statements in the interpreter body to short-circuit various steps that otherwise result in larger code due to duplication that the compiler is otherwise not able to eliminate as common subexpressions. This results in less code but does introduce unconditional jumps to common code. These should be eliminated at runtime by any CPUs that use branch predictors.
- `_GVM_OPT_PROFILE_OPCODE_COUNTS_` Enables an end of execution report giving the counts of each interpreted opcode executed.
- `_GVM_OPT_BCC_16_BIT_` By default, compare and branch operations have an 8-bit displacement for the branch target. Enabling this flag switches to a binary incompatible 16-bit variant. Code assembled for one model is not compatible with the other as it will result in the interpreter branching or continuing from the wrong location.
- `_GVM_OPT_64BIT_PURE_` - For 64-bit hosts, redefines the entire architecture to use 64-bit scalar values instead of 32-bit.
- `_GVM_DEBUGGING_` Enables miscellaneous debug output.
- `_GVM_DEBUG_FUNCTIONS_` Debugs the entry and exit of functions within the interpreted code.
- `_GVM_DEBUG_OPCODES_` Emits a dissassembly and outcome of each instruction interpreted. This is extremely verbose.
