/**
 * TOYTL - GVM
 *
 * Twenty Odd Years Too Late Game Virtual Machine
 */

    // x =  v1.y * v2.z - v1.z * v2.y,
    // y =  v1.z * v2.x - v1.x * v2.z,
    // z =  v1.x * v2.y - v1.y * v2.x#
    vd[0] = vs1[1] * vs2[2] - vs1[2] * vs2[1];
    vd[1] = vs1[2] * vs2[0] - vs1[0] * vs2[2];
    vd[2] = vs1[0] * vs2[1] - vs1[1] * vs2[0];
    STEP(4);
    NEXT;
