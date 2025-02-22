#include <iostream>
#include <vector>
using namespace std;
vector<int> fiboNum;
int fibo(int n) {
    for (int i=3; i<=n; i++) {
        fiboNum[i] = fiboNum[i-1]% 15746 + fiboNum[i-2]% 15746;
    }
    return fiboNum[n];
}
int main() {
    fiboNum.resize(1000000,0);
    fiboNum[0] = 0;
    fiboNum[1] = 1;
    fiboNum[2] = 2;
    int n;
    cin >> n;
    cout << fibo(n) % 15746;


    return 0;
}
/*
1 -> 1 1
2 -> 00 11 2
3 -> 100 001 111 3
4 -> 0011 1100 0000 1001 1111 5
5 -> 11111 11100 11001 10011 00111 10000 00001 00100 8
6 -> 111111 111100 111001 110011 100111 001111 110000 100001 000011 001100 100100 001001 000000 13

f(n) = f(n-1) + f(n-2)
*/
