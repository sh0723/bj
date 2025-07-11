#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N;
    cin >> N;

    vector<int> stair(N);
    for (int i=0; i<N; i++) {
        cin >> stair[i];
    }

    vector<vector<int>> sum(N,vector<int>(3));
    sum[0][0] = 0;
    sum[0][1] = stair[0];
    sum[0][2] = stair[0];

    for (int i=1; i<N; i++) {
        if (i==1) {
            sum[i][0] = stair[i];
            sum[i][1] = stair[i] + stair[i-1];
            sum[i][2] = sum[i][1];
        } else {
            sum[i][0] = max(sum[i-2][1],sum[i-2][0]) + stair[i]; // 2칸 아래
            sum[i][1] = sum[i-1][0] + stair[i]; // 1칸 아래
            sum[i][2] = max(sum[i][0], sum[i][1]);
        }
    }

    cout << sum[N-1][2];


    return 0;
}