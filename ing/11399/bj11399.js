"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var fs = require("fs");
var input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
var n = Number(input[0]);
var nums = input[1].split(' ').map(Number);
nums.sort(function (a, b) { return a - b; });
var sum = Array(nums.length + 1).fill(0);
for (var i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + nums[i - 1];
}
var output = 0;
for (var i = 1; i <= n; i++) {
    output = output + sum[i];
}
console.log(output);
