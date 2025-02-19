#include<iostream>
#include <cmath>
#include <vector>

using namespace std;
int N;
int cnt = 0;
vector<pair<int,int>> board;

bool check(int row, int col) {
     for (int i=0; i<board.size(); i++) {
        if (board[i].second == col || abs(board[i].first - row) == abs(board[i].second - col))
            return false;
     }
     return true;
}

void dfs(int row) {
    
    if (row == N+1) {
        cnt++;
        return;
    }
    
    for (int col=0; col<N; col++) {
        if (check(row,col)) {
            board.push_back({row,col});
            dfs(row+1); 
            board.pop_back();
        }
    }
    
}

int main() {

    cin >> N;
    dfs(1);
    cout << cnt << endl;

    return 0;
}

