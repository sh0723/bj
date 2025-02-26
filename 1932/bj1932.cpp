#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<vector<int>> triangleNum(N);
    vector<vector<int>> dp(N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<i+1; j++) {
            int num;
            cin >> num;
            triangleNum[i].push_back(num);
        }
        dp[i].resize(i+1);
    }

    dp[0][0] = triangleNum[0][0];

    for (int i=1; i<N; i++) {
        for (int j=0; j<i+1; j++) {
            if (j == 0) {
                dp[i][j] = dp[i-1][j] + triangleNum[i][j];
            }
            else if (j == i) {
                dp[i][j] = dp[i-1][j-1] + triangleNum[i][j];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + triangleNum[i][j];
            }

        }
    }

    int maxNum = INT_MIN;

    for (int i=0; i<N; i++) {
        if (dp[N-1][i] > maxNum)
            maxNum = dp[N-1][i];
    }

    cout << maxNum;

    return 0;
}