
@doNothing: // ():void
    ret

@doSomething: // ():void
    call @doNothing
    addr $testData, i1
    cgt.f (0), (1), #100
    ret

$testData:
