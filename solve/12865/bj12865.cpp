#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;

    vector<pair<int,int> > v(n,{0,0}); // 0. Weight, 1. Value
    vector<int> dp(k+1,0);

    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        cin >> v[i].second;
    }


    for (int i=0; i<n; i++) {
        for (int j=k; j >= v[i].first; j--) {
            dp[j] = max(dp[j], dp[j-v[i].first] + v[i].second);
        }
    }

    cout << dp[k];

}

/*
 이 문제는 다른 문제들처럼 index가 작은것 -> 큰것인 방향이 아닌 큰것 -> 작은것 방향으로 풀어야함
 최대 담을 수 있는 크기에서 입력받은 (무게, 가치) 를 대입 하면서 최대치 dp배열 최신화 하는 방식
 */