for (var numerus = 1; numerus <= 100; ++numerus) {

    if (numerus % 3 === 0 && numerus % 5 === 0) console.log("FizzBuzz");
    else if (numerus % 3 === 0) console.log("Fizz");
    else if (numerus % 5 === 0) console.log("Buzz");
    else console.log(numerus);
}
