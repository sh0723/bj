"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var fs = require("fs");
var input = fs.readFileSync('/dev/stdin').toString().trim();
var numbers = input.split(/[+-]/).map(Number);
var operators = input.match(/[+-]/g) || [];
var output = numbers[0];
var operators_count = 0;
var minus_valid = true;
for (var i = 1; i < numbers.length; i++) {
    if (operators[operators_count] == '-' && minus_valid) {
        output -= numbers[i];
        minus_valid = false;
        operators_count++;
        continue;
    }
    if (operators[operators_count] == '-' && !minus_valid) {
        minus_valid = true;
        output -= numbers[i];
        operators_count++;
        continue;
    }
    if (operators[operators_count] == '+' && minus_valid) {
        output += numbers[i];
        operators_count++;
        continue;
    }
    if (operators[operators_count] == '+' && !minus_valid) {
        output -= numbers[i];
        operators_count++;
        continue;
    }
}
console.log(output);
