#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main() {
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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
            sum[i][j] = sum[i][j-1] + sum[i-1][j] + vector_map[i-1][j-1] - sum[i-1][j-1];
        }
    }


    for (int i=0; i<M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1] << '\n';
    }






    return 0;
}

/*
 0,0 ~ i,j 까지의 합으로 누적합을 계산해야하는걸 떠올리는게 Point였던 문제.
 */