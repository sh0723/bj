#include<iostream>
#include<vector>

using namespace std;

int main() {
    int num, n;
    cin >> n >> num;
    vector<int> v(n);
    vector<int> count_same_num(num,0);
    vector<int> v_to_output(n,0);
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    v_to_output[0] = v[0];
    for (int i = 1; i < n; i++) {
        v_to_output[i] = v_to_output[i-1] + v[i];
    }

    for (int i = 0; i < n; i++) {
        v_to_output[i] %= num;
    }

    for (int i=0; i<num; i++) {
        for (int j=0; j<n; j++) {
            if (v_to_output[j] == i) {
                count_same_num[i]++;
            }
        }
    }

    int output = count_same_num[0];
    for (int i=0; i<=num; i++) {
        for (int j=0; j<=i; j++) {
            if (j == 0 || i == j) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    for (int i=1; i<num; i++) {
        output += dp[count_same_num[i]][2];
    }

    cout << output << endl;
}

/*
5 3
1 2 3 1 2
1 2 9 7 8
1 3 6 7 9

1 3 1 2 4 2 3 4 1 2

 */