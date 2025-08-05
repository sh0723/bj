#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool sorting_function(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }

    return p1.second < p2.second;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int> > inp(n);

    for (int i = 0; i < n; i++) {
        cin >> inp[i].first;
        cin >> inp[i].second;
    }

    sort(inp.begin(), inp.end(), sorting_function);

    int count = 1;
    int ed = inp[0].second;
    for (int i=1; i<n; i++) {
        if (ed <= inp[i].first) {
            ed = inp[i].second;
            count++;
        }
    }

    cout << count << endl;
    return 0;
}