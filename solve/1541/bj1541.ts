import * as fs from 'fs';

const input : string = fs.readFileSync('/dev/stdin').toString().trim();

const numbers : number[] = input.split(/[+-]/).map(Number);

const operators : string[] = input.match(/[+-]/g) || [];

var output : number = numbers[0];
var operators_count : number = 0;
var minus_valid : boolean = true;

for (var i=1; i<numbers.length; i++) {
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
