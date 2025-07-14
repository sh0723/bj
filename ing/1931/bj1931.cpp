#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> inp;

    for (int i = 0; i < n; i++) {
        int st,ed;
        cin >> st >> ed;
        if (!inp.count(st)) {
            inp[st] = ed;
        } else {
            if (inp[st] > ed) {
                inp[st] = ed;
            }
        }
    }

    int max = 0;
    for (auto& n : inp) {
        int st = n.first;
        int ed = n.second;
        int count = 1;
        for (auto& e : inp) {
            if (e.first >= ed) {
                count++;
                st = e.first;
                ed = e.second;
            }
        }

        if (count > max) {
            max = count;
        }
    }

    cout << max << endl;
}