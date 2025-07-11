#include<iostream>
#include<vector>

using namespace std;

int main() {
    int num, n;
    cin >> n >> num;
    vector<int> v(n);
    vector<int> count_same_num(num,0);
    vector<int> v_to_output(n+1,0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    count_same_num[0]++;
    for (int i = 1; i <= n; i++) {
        v_to_output[i] = (v_to_output[i-1] + v[i-1]) % num;
        count_same_num[v_to_output[i]]++;
    }

    long long count = 0;
    for (int i = 0; i < num; i++) {
        if (count_same_num[i] <= 0) {
            continue;
        }
        count += 1LL * count_same_num[i] * (count_same_num[i]-1) / 2;
    }

    cout << count << endl;
    return 0;
}

// 전체적인 아이디어는 잘 생각해냄, 하지만 0부터 시작하는 경우를 생각 안함..!