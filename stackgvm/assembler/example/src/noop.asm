
@doNothing: // ():void
    ret

@doSomething: // ():void
    call @doNothing
    addr $testData, i1
    cgt.f (0), (i0+1), .dummy
    ret

$testData:
