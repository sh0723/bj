#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> map;

bool control_press(int n, int x, int y);
void press(int n, int x, int y);
int main() {

    int n;
    cin >> n;

    map.resize(n, vector<int>(n, 0));
    vector<string> inp(n, string());
    for (int i = 0; i < n; i++) {
        cin >> inp[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            map[i][j] = inp[i][j] - '0';
        }
    }


    press(n, 0, 0);

    return 0;
}

bool control_press(int n, int x, int y) {
    int st_num = map[x][y];
    bool flag = true;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (map[x+i][y+j] != st_num) {
                flag = false;
            }
        }
    }
    return flag;
}

void press(int n, int x, int y) {
    if (control_press(n, x, y)) {
        cout << map[x][y];
    } else {
        cout << '(';
        press(n/2, x, y);
        press(n/2, x, y+n/2);
        press(n/2, x+n/2, y);
        press(n/2, x+n/2, y+n/2);
        cout << ')';
    }

}