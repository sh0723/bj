#include <iostream>
#include <vector>
using namespace std;
vector<long> resultNum;
long dp(int n) {

    for (int i=6; i<=n; i++) {
        resultNum[i] = resultNum[i-5] + resultNum[i-1];
    }

    return resultNum[n];
}
int main() {
    resultNum.resize(100,0);
    resultNum[0] = 0;
    resultNum[1] = 1;
    resultNum[2] = 1;
    resultNum[3] = 1;
    resultNum[4] = 2;
    resultNum[5] = 2;

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        cout << dp(num) << endl;
    }

    return 0;
}