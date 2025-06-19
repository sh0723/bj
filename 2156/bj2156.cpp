#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int num;
    cin >> num;

    vector<int> arr(num);
    vector<vector<int>> dp(num, vector<int>(3, 0));
    for (int i=0 ; i<num ; i++) {
        int temp_num;
        cin >> temp_num;
        arr[i] = temp_num;
    }

    dp[0][1] = arr[0];
    if (num >= 2) {
        dp[1][0] = dp[0][1];
        dp[1][1] = arr[1];
        dp[1][2] = dp[0][1] + arr[1];
        if (num >= 3) {
            int max_zero_num = max(dp[1][0], dp[1][1]);
            dp[2][0] = max(max_zero_num, dp[1][2]);
            dp[2][1] = dp[1][0] + arr[2];
            dp[2][2] = dp[1][1] + arr[2];
            if (num >= 4) {
                max_zero_num = max(dp[2][0], dp[2][1]);
                dp[3][0] = max(max_zero_num, dp[2][2]);
                dp[3][1] = dp[2][0] + arr[3];
                dp[3][2] = dp[2][1] + arr[3];
            }
        }
    }
    // 0은 선택 안함 -> 이전꺼의 최대값 반영
    // 1은 처음 선택 -> [i-1][0] + arr[i]
    // 2는 두번째 선택 -> [i-1][1] + arr[i]
    int max_zero_num;
    for (int i=4; i<num; i++) {
        max_zero_num = max(dp[i-1][0], dp[i-1][1]);
        dp[i][0] = max(max_zero_num, dp[i-1][2]);
        dp[i][1] = dp[i-1][0] + arr[i];
        dp[i][2] = dp[i-1][1] + arr[i];
    }

    int result = 0;
    result = max(dp[num-1][0], dp[num-1][1]);
    result = max(result, dp[num-1][2]);

    cout << result << endl;
}
