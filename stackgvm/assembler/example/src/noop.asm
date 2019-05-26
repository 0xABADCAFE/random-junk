@aliasTests: // ():void
    ble.i (0),    (1),      .dummy
    ble.i (2),    (i0+3),   .dummy
    ble.i (i0+4), (5),      .dummy
    ble.i (i0+6), (i1+7),   .dummy
    blt.i (8),    (9),      .dummy
    blt.i (10),   (i0+11),  .dummy
    blt.i (i0+12), (13),    .dummy
    blt.i (i0+14), (i1+15), .dummy
    ble.f (16),    (17),    .dummy
    ble.f (18),    (i0+19), .dummy
    ble.f (i0+20), (21),    .dummy
    ble.f (i0+22), (i1+23), .dummy
    blt.f (24),    (25),    .dummy
    blt.f (26),    (i0+27), .dummy
    blt.f (i0+28), (29),    .dummy
    blt.f (i0+30), (i1+31), .dummy
    ret
