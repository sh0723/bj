#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> Chess(N+1, vector<int>(M+1, 0));
    char c;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin >> c;
            if (c == 'B') {
                Chess[i][j] = 1;
            }

            if (c == 'W') {
                Chess[i][j] = 0;
            }
        }
    }

    vector<vector<int>> error_map_zero(N+1, vector<int>(M+1, 0));
    vector<vector<int>> error_map_one(N+1, vector<int>(M+1, 0));

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {

            int expected_zero = ((i + j) % 2 == 0) ? 0 : 1;
            error_map_zero[i][j] = (Chess[i][j] != expected_zero) ? 1 : 0;

            int expected_one = ((i + j) % 2 == 0) ? 1 : 0;
            error_map_one[i][j] = (Chess[i][j] != expected_one) ? 1 : 0;

        }
    }

    vector<vector<int>> error_map_sum_zero(N+1, vector<int>(M+1, 0));
    vector<vector<int>> error_map_sum_one(N+1, vector<int>(M+1, 0));

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            error_map_sum_zero[i][j] = error_map_sum_zero[i-1][j] + error_map_sum_zero[i][j-1] - error_map_sum_zero[i-1][j-1] + error_map_zero[i][j];
            error_map_sum_one[i][j] = error_map_sum_one[i-1][j] + error_map_sum_one[i][j-1] - error_map_sum_one[i-1][j-1] + error_map_one[i][j];
        }
    }

    int ans = K * K;  // 최대는 전부 칠하는 것

    for (int i = 1; i + K - 1 <= N; i++) {
        for (int j = 1; j + K - 1 <= M; j++) {
            int x1 = i;
            int y1 = j;
            int x2 = i + K - 1;
            int y2 = j + K - 1;

            int wrong_zero = error_map_sum_zero[x2][y2]
                            - error_map_sum_zero[x1-1][y2]
                            - error_map_sum_zero[x2][y1-1]
                            + error_map_sum_zero[x1-1][y1-1];

            int wrong_one = error_map_sum_one[x2][y2]
                           - error_map_sum_one[x1-1][y2]
                           - error_map_sum_one[x2][y1-1]
                           + error_map_sum_one[x1-1][y1-1];

            int repaint_zero = min(wrong_zero, K*K - wrong_zero);
            int repaint_one  = min(wrong_one,  K*K - wrong_one);

            ans = min(ans, min(repaint_zero, repaint_one));
        }
    }

    cout << ans << endl;


    return 0;
}

/*
 솔직히 잘 모르겟음... 그냥 이거만 틀렷음으로 남기기 싫어서..! 나중에 꼭 풀도록 하자
 */