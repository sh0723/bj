#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;

    vector<int> numArr(n+1,0);
    numArr[0] = 0;
    numArr[1] = 0;
    numArr[2] = 1;
    numArr[3] = 1;

    for (int i=1; i<n; i++) {
        if (i + 1 <= n) {
            if (numArr[i+1] == 0) {
                numArr[i+1] = numArr[i] + 1;
            } else {
                numArr[i+1] = min(numArr[i] + 1, numArr[i+1]);
            }
        }

        if (i * 2 <= n) {
            if (numArr[i*2] == 0) {
                numArr[i*2] = numArr[i] + 1;
            } else {
                numArr[i*2] = min(numArr[i] + 1, numArr[i*2]);
            }
        }

        if (i * 3 <= n) {
            if (numArr[i*3] == 0) {
                numArr[i*3] = numArr[i] + 1;
            } else {
                numArr[i*3] = min(numArr[i] + 1, numArr[i*3]);
            }
        }
    }

    cout << numArr[n];

    return 0;
}
/*
 f(1) = 0
 f(2) = 1
 f(3) = 1
 f(4) = f(2) + 1  // 2
 f(5) = f(4) + 1 // 3
 f(6) = f(3) + 1 // 2
 f(7) = f(6) + 1 // 3
 f(8) = f(4) + 1 // 3
 f(9) = f(3) + 1 // 2
 f(10) = f(5) + 1
 f(11) = f(10) + 1

 n + 1 , n * 2 , n * 3
 min ( f( n+1 ) , f( n*2 ), f( n*3) ))
 */