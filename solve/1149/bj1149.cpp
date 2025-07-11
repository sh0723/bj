#include <iostream>
#include <vector>
#include <climits>
using namespace std;
struct colorStruct {
    int colorArr[3];
};
int main() {
    int minValue = INT_MAX;
    int N;
    cin >> N;
    vector<vector<int>> color;
    vector<vector<int>> minPrice;

    color.resize(N,vector<int>(3));
    minPrice.resize(N,vector<int>(3));

    for (int i=0; i<N; i++) {
        cin >> color[i][0] >> color[i][1] >> color[i][2];
    }

    minPrice[0][0] = color[0][0];
    minPrice[0][1] = color[0][1];
    minPrice[0][2] = color[0][2];

    for (int i=1; i<N; i++) {
        minPrice[i][0] = min(minPrice[i-1][1],minPrice[i-1][2]) + color[i][0];
        minPrice[i][1] = min(minPrice[i-1][0],minPrice[i-1][2]) + color[i][1];
        minPrice[i][2] = min(minPrice[i-1][1],minPrice[i-1][0]) + color[i][2];
    }

    for (int i=0; i<3; i++) {
        if (minPrice[N-1][i] < minValue) {
            minValue = minPrice[N-1][i];
        }
    }

    cout << minValue;
    return 0;
}
