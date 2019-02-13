# TOYTL StackGVM

A 32-bit pure VM intended for use within the TOYTL Engine. This provides support for 32-bit integer, floating point and vector operations where a vector is defined as a triplet of 3 floating point values.

- Instructions are implemented as pure byte code comprising of between 1 to 5 bytes typically.
- Instructions have up to three operands. Generally all dyadic operations have 3, two source operands and a destination.
- 16-bit values are used for branch targets and identifiers for function IDs, global data references etc. Where these are present in the byte code, they are stored MSB first.

The implementation is not instanced. A single static class forms the basis of the interpreter. This is a deliberate choice as there is no use case within the TOYTL Engine for more than one instance and removing the hidden indirection improves performance.

The implementation is neither a register machine or a pure stack machine. Instead, a stack frame model is used in which every function defines a stack frame that gives each invocation of that function the space required for it's return, parameters and any local temporaries. Instructions operating on the stack frame interpret their operands as offsets.

Since only 32-bit scalar types are supported, the machine allows indirection. Every frame has a pair of indirection pointers that can be assigned an address, permitting instructions that support indirection to do operate directly on the target data.
