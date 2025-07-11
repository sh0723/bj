#include <iostream>
#include <vector>
using namespace std;
int N;
int minNum = 1000000;
vector<bool> flag;
vector<vector<int>> abilityScore;
void dfs(int cnt, int idx);
int main() {

    cin >> N;
    abilityScore.resize(N, vector<int>(N, 0));
    flag.resize(N,true);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> abilityScore[i][j];
        }
    }

    dfs(0,0);
    cout << minNum;

    return 0;
}
void dfs(int cnt, int idx) {
    if (cnt == N/2) {
        int start = 0;
        int link = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (i != j) {
                    if (flag[i] && flag[j]) {
                        start += abilityScore[i][j];
                    }
                    if (!flag[i] && !flag[j]) {
                        link += abilityScore[i][j];
                    }
                }
            }
        }

        if (abs(start-link) < minNum) {
            minNum = abs(start-link);
        }
        return;
    }

    for (int i=idx; i<N; i++) {
        if (flag[i]) {
            flag[i] = false;
            dfs(cnt+1, i+1);
            flag[i] = true;
        }
    }
}