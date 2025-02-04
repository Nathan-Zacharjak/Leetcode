/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
    let num1 = 0
    let num2 = 1

    while(true){
        yield num1
        const temp = num1
        num1 = num2
        num2 += temp
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */