#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main() {

    int N, M;
    cin >> N >> M;

    vector<vector<int>> vector_map(N, vector<int>(N, 0));

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> vector_map[i][j];
        }
    }

    vector<vector<int>> sum(N+1, vector<int>(N+1, 0));

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            sum[i][j] = sum[i][j-1] + vector_map[i-1][j-1];
        }
    }

    vector<tuple<int, int, int, int>> pairs;

    for (int i=0; i<M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        pairs.push_back(make_tuple(x1, y1, x2, y2));
    }

    for (int i=0; i<M; i++) {
        int x1, y1, x2, y2;
        x1 = get<0>(pairs[i]);
        y1 = get<1>(pairs[i]);
        x2 = get<2>(pairs[i]);
        y2 = get<3>(pairs[i]);

        int sum_to_output = 0;
        for (int i=x1; i<=x2; i++) {
            sum_to_output += (sum[i][y2] - sum[i][y1-1]);
        }

        cout << sum_to_output << endl;
    }




    return 0;
}