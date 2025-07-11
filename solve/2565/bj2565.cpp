#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

bool compareByFirst(tuple<int, int, int> p1, tuple<int, int, int> p2) {
    return get<0>(p1) < get<0>(p2);
}

int main() {

    int n;
    cin >> n;

    vector<tuple<int, int, int>> arr(n);

    for (int i = 0; i < n; i++) {
        int first, second;
        cin >> first >> second;
        arr[i] = make_tuple(first, second, 1);
    }

    sort(arr.begin(), arr.end(), compareByFirst);

    for (int i = 0; i < n; i++) {
        for (int j=i-1; j >=0; j--) {
            if (get<1>(arr[i]) > get<1>(arr[j]) && get<2>(arr[i]) < get<2>(arr[j]) + 1) {
                get<2>(arr[i]) = get<2>(arr[j]) + 1;
            }
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        if (get<2>(arr[i]) > max) {
            max = get<2>(arr[i]);
        }
    }

    cout << n - max;

    return 0;
}