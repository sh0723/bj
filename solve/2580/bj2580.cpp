#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int>> zeroSpace;
int board[9][9] = {0};
void checkWhereIsZero();
bool isValid(int column, int row, int num);
bool solveSdoque(int index);
int main() {

    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cin >> board[i][j];
        }
    }

    checkWhereIsZero();
    solveSdoque(0);

}
void checkWhereIsZero() {
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            if (board[i][j] == 0) {
                zeroSpace.push_back(make_pair(i,j));
            }
        }
    }
}
bool solveSdoque(int index) {
    if (index == zeroSpace.size()) {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }

    int column = zeroSpace[index].first;
    int row = zeroSpace[index].second;

    for (int i=1; i<10; i++) {
        if (isValid(column,row,i)) {
            board[column][row] = i;
            if (solveSdoque(index+1))
                return true;
            board[column][row] = 0;
        }
    }
    return false;
}
bool isValid(int column, int row, int num) {
    for (int i=0; i<9; i++) {
        if (board[column][i] == num)
            return false;
    }

    for (int i=0; i<9; i++) {
        if (board[i][row] == num)
            return false;
    }

    int stColumn = (column/3) * 3;
    int stRow = (row/3) * 3;

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (board[i+stColumn][j+stRow] == num)
                return false;
        }
    }

    return true;
}



