#include <iostream>
#include <vector>
#include <climits>
using namespace std;
struct colorStruct {
    int colorArr[3];
};
int minValue = INT_MAX;
int N;
vector<colorStruct> color;
void dfs(int price, int houseCount, int selectedColor) {

    if (houseCount == N) {
        if (price < minValue) {
            minValue = price;
        }
        return;
    }

    for (int i=0; i<3; i++) {
        if (price != 0 && selectedColor == i)
            continue;
        price += color[houseCount].colorArr[i];
        if (price > minValue) {
            return;
        }
        dfs(price, houseCount+1, i);
        price -= color[houseCount].colorArr[i];
    }
}
int main() {
    cin >> N;

    for (int i=0; i<N; i++) {
        colorStruct colors;
        cin >> colors.colorArr[0] >> colors.colorArr[1] >> colors.colorArr[2];

        color.push_back(colors);
    }

    dfs(0,0,0);
    cout << minValue;



    return 0;
}