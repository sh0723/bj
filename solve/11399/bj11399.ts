import * as fs from 'fs';


const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const n : number = Number(input[0]);
const nums : number[] = input[1].split(' ').map(Number);

nums.sort((a, b) => a - b);

const sum : number[] = Array(nums.length + 1).fill(0);

for (let i = 1; i<=n; i++ ) {
    sum[i] = sum[i-1] + nums[i-1];
}

var output : number = 0;

for (let i = 1; i<=n; i++) {
    output = output + sum[i];
}

console.log(output);
