var gpio = require('./gpio'); // FIXME

console.log(gpio.hello());

console.log("set mode");

console.log(gpio.getPinMode(17));
console.log(gpio.setPinMode(17, 0));
console.log(gpio.getPinMode(17));
console.log(gpio.setPinMode(17, 1));
console.log(gpio.getPinMode(17));

console.log("set value");

console.log(gpio.getPinValue(17));
console.log(gpio.setPinValue(17, 0));
console.log(gpio.getPinValue(17));