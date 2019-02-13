/**
 * TOYTL - GVM
 *
 * Twenty Odd Years Too Late Game Virtual Machine
 */

    if (result != SUCCESS) {
        dumpCallStack();
        EXIT(result);
    }
    UPDATE_PTRS;
    NEXT;
