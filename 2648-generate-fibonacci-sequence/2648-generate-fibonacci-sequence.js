/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
    yield 0
    yield 1
    let num1 = 0
    let num2 = 1
    let value = 0
    while(true){
        value = num1 + num2
        num1 = num2
        num2 = value
        yield value
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */