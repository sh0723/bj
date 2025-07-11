#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int s1_length = s1.size();
    int s2_length = s2.size();

    vector<vector<int>> dp(s1_length + 1, vector<int>(s2_length + 1, 0));
    for (int i = 1; i <= s1_length; i++) {
        for (int j = 1; j <= s2_length; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[s1_length][s2_length] << endl;

}

/*
 i, j 까지 겹치는 부분의 길이를 차례차례 구하는 것까진 생각하기 쉬움.
 포인트는 i,j에서의 점화식을 구하는 부분 !
 */