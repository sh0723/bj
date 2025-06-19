#include <iostream>
#define MOD 1000000000
using namespace std;

long long dp[101][10];

int main() {
    long n;
    cin >> n;

    for (int i=1; i < 10; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][1] % MOD;
        dp[i][9] = dp[i - 1][8] % MOD;

        for (int j = 1; j < 9; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
        }
    }


    long long result = 0;


    for (int i=0 ;i<10; i++) {

        result = (result + (dp[n][i] % MOD)) % MOD;
    }

    cout << result << endl;

    return 0;

}

/*
 0 , 9 에서는 이전의 1, 이전의 8의 값
 나머지는 n-1 n+1 의 합과 같다는 것을 활용한 dp문제
 */