#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<pair<int,int>> sector(m);
    for (int i = 0; i < m; i++) {
        cin >> sector[i].first >> sector[i].second;
    }

    vector<int> sum(n+1,0);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i-1] + v[i-1];
    }

    for (int i = 0; i < m; i++) {
        cout << sum[sector[i].second] - sum[sector[i].first - 1] << '\n';
    }
}

// 0~n 까지의 합에서 i~j 까지의 합만 구하려면 0~i-1 까지의 합을 0~j까지의 합에서 빼면 됨