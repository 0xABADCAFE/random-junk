/**
 * TOYTL - GVM
 *
 * Twenty Odd Years Too Late Game Virtual Machine
 */

#ifndef _GVM_CORE_HPP_
    #define _GVM_CORE_HPP_
    #include "host_machine.hpp"
    #include "gvm_opcode.hpp"
    #include "gvm_scalar.hpp"
    
namespace GVM {

    typedef enum {
        SUCCESS                    = 0,

        // Runtime execution result statuses
        EXEC_RETURN_TO_HOST        = 1,
        EXEC_HALT_AND_CATCH_FIRE   = 2,
        EXEC_CALL_STACK_OVERFLOW   = 3,
        EXEC_CALL_STACK_UNDERFLOW  = 4,
        EXEC_FRAME_STACK_OVERFLOW  = 5,
        EXEC_FRAME_STACK_UNDERFLOW = 6,
        EXEC_ILLEGAL_CALL_ID       = 7,
        EXEC_ILLEGAL_HOST_ID       = 8,
        EXEC_ILLEGAL_DATA_ID       = 9,
        EXEC_DIVISION_BY_ZERO      = 10,

        // Initialisation failures
        INIT_OUT_OF_MEMORY         = 100,
        INIT_TABLE_TOO_BIG         = 101,
        INIT_INVALID_FRAME_DEF     = 102,

        // Miscellaneous failures
        MISC_ILLEGAL_VALUE         = 1000,
        MISC_ALL_GONE_PETE_TONG    = 9001

    } Result;

    // Symbol ID values are 16 bit. When an ID is stored into a Scalar for later use, it is combined with a 2-bit
    // tag value that identifies it as data, code or host. Whenever a Scalar is used to dereference a Symbol ID,
    // the tag type is checked.
    typedef enum {
        TAG_ILLEGAL        = 0,
        TAG_DATA_REFERENCE = 1 << 30,
        TAG_CODE_REFERENCE = 2 << 30,
        TAG_HOST_REFERNECE = 3 << 30,
        TAG_MASK_REFERENCE = 3 << 30
    } SymbolIDTypeTag;



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

    typedef Result (*HostCall)(Scalar* stackFrame);

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

            static Result  init(
                const size_t rSize,
                const size_t fSize,
                const FuncInfo* func,
                const HostCall* host,
                Scalar** data
            );
            static Result  invoke(const uint16 functionId);
            static void    done();

            static Scalar* stack() {
                return frameStack;
            }

        private:
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

            // Primary allocation for all stack data
            static void*           workingSet;
            static CallInfo*       callStack;
            static CallInfo*       callStackBase;
            static CallInfo*       callStackTop;
            static Scalar*         frameStack;
            static Scalar*         frameStackBase;
            static Scalar*         frameStackTop;
            static const uint8*    programCounter;
            static const FuncInfo* functionTable;
            static uint32          functionTableSize;
            static const HostCall* hostFunctionTable;
            static uint32          hostFunctionTableSize;
            static Scalar**        dataTable;
            static uint32          dataTableSize;

            static Result enterFunction(const uint8* returnAddress, const uint16 functionId);
            static Result enterClosure(const uint8* returnAddress, const int16 branch, const uint8 frameSize);
            static Result exitFunction();
            static Result invokeHostFunction(const uint16 functionId);
            static Result run();
            static int    evaluateExtendedAddress3(const uint8* pc, Scalar*& op1, Scalar*& op2, Scalar*& op3);
            static Result validateTables(const FuncInfo* func, const HostCall* host, Scalar** data);
            static void   dumpFrame();
            static void   dumpCallStack();
    };

};

#endif
