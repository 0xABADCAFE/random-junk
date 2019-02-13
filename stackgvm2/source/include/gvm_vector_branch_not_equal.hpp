/**
 * TOYTL - GVM
 *
 * Twenty Odd Years Too Late Game Virtual Machine
 */

    if (
        ud[0] != us[0] ||
        ud[1] != us[1] ||
        ud[2] != us[2]
    ) {
        STEP(J16(2));
        NEXT;
    }
    STEP(5);
    NEXT;

