#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int maxNum = INT_MIN;
vector<int> numArr;
vector<int> maxArr;
int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        numArr.push_back(num);
    }

    maxArr.resize(n);
    maxArr[0] = numArr[0];
    for (int i=1; i<n; i++) {
        maxArr[i] = max(numArr[i], maxArr[i-1] + numArr[i]);
    }

    for (int i=0; i<n; i++) {
        if (maxArr[i] > maxNum)
            maxNum = maxArr[i];
    }
    cout << maxNum;

    return 0;
}
/*
0
01 1
012 12 2
0123 123 23 3
 */