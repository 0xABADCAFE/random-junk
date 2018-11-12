/**
 * TOYTL - GVM
 *
 * Twenty Odd Years Too Late Game Virtual Machine
 */

#ifndef _GVM_CORE_HPP_
    #define _GVM_CORE_HPP_
    #include "host_machine.hpp"
    #include "gvm_opcode.hpp"

namespace GVM {

    /**
     * Scalar
     *
     * Basic machine datatype.
     */
    union Scalar {
        int32   i;
        uint32  u;
        float32 f;
    };

    /**
     * FuncInfo
     *
     * Describes the runtime resolved properties of an enumerated, callable function.
     */
    struct FuncInfo {
        uint8* entryPoint;
        uint8  frameSize;
        uint8  returnSize;
        uint8  paramSize;
        uint8  localSize;

        enum {
            MAX_RETURN_SIZE = 4,
            MAX_PARAM_SIZE  = 16,
            MAX_LOCAL_SIZE  = 88,
            MAX_FRAME_SIZE  = 108,
            MAX_ID          = (1<<16)-1
        };
    };

    /**
     * CallInfo
     *
     * Describes the current function under evaluation.
     */
    struct CallInfo {
        const uint8* returnAddress;
        Scalar*      indirection[2];
        uint16       functionId;
        uint8        frameSize;
        uint8        reserved;
    };

    /**
     * Interpreter
     *
     * Main execution engine.
     */
    class Interpreter {
        public:
            enum {
                MIN_CALL_DEPTH = 8,
                MAX_CALL_DEPTH = 256,
                MIN_STACK_SIZE = FuncInfo::MAX_FRAME_SIZE,
                MAX_STACK_SIZE = FuncInfo::MAX_FRAME_SIZE * MAX_CALL_DEPTH,
                REDZONE_BUFFER = 128
            };

            typedef enum {
                SUCCESS                   = 0,
                EXEC_HALT_AND_CATCH_FIRE  = 1,
                EXEC_CALL_STACK_OVERFLOW  = 2,
                EXEC_FRAME_STACK_OVERFLOW = 3,
                EXEC_ILLEGAL_CALL_ID      = 4,
                EXEC_ILLEGAL_HOST_ID      = 5,
                EXEC_ILLEGAL_DATA_ID      = 6,
                INIT_OUT_OF_MEMORY        = 100,
                INIT_TABLE_TOO_BIG        = 101,
                INIT_INVALID_FRAME_DEF    = 102,
                MISC_ILLEGAL_VALUE        = 1000

            } Result;

            static Result init(size_t rSize, size_t fSize, const FuncInfo* table);
            static Result execute(uint16 functionId);
            static void   done();

        private:
            // Primary allocation for all stack data
            static void*     workingSet;

            static CallInfo* callStack;
            static CallInfo* callStackBase;
            static CallInfo* callStackTop;
            static Scalar*   frameStack;
            static Scalar*   frameStackBase;
            static Scalar*   frameStackTop;

            static const uint8*    programCounter;
            static const FuncInfo* functionTable;
            static uint32          functionTableSize;

            static void initCallInfo(const uint8* ret, uint16 id, uint8 fs) {
                callStack->returnAddress = ret;
                callStack->functionId    = id;
                callStack->frameSize     = fs;
            }

            static Result enterFunction(const uint8* returnAddress, uint16 functionId, uint8 frameSize = 0);
            static Result exitFunction();

            static Result validateFunctionTable(const FuncInfo* table);
    };

};

#endif
