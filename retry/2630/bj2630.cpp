#include <iostream>
#include <vector>

using namespace std;
bool checkIsSame(int n, int x, int y);
void divide(int n, int x, int y);
vector<vector<int>> map;
int zero_count = 0;
int one_count = 0;
int main() {

    int number;
    cin >> number;
    map.resize(number, vector<int>(number, 0));

    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            cin >> map[i][j];
        }
    }

    divide(number,0,0);

    cout << zero_count << endl;
    cout << one_count << endl;


    return 0;
}

void divide(int n, int x, int y) {
    if (checkIsSame(n, x, y)) {
        if (map[x][y] == 0)
            zero_count++;
        else
            one_count++;
        return;
    }

    int half = n / 2;
    divide(half,x, y);
    divide(half,x+half, y);
    divide(half,x, y+half);
    divide(half,x+half, y+half);
}

bool checkIsSame(int n, int x, int y) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[x+i][y+j] != map[x][y])
                return false;
        }
    }

    return true;
}
