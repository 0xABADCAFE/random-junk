
@doNothing: // ():void
    ret

@doSomething: // ():void
    call @doNothing
    addr $testData, i1
    ret

$testData:
