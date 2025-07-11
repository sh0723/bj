#include <iostream>
#include <vector>
using namespace std;
int N;
int minNum = 1000000000;
int maxNum = -1000000000;
int calculator[4] = {0};
vector<int> numArr;
void getResult(int index, char calcArr[]);
int applyOperation(int a, int b, char op);
int calculateFunction(char calcArr[]);
int main() {

    cin >> N;

    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        numArr.push_back(num);
    }

    char calcArr[N];

    for (int i=0; i<4; i++) {
        cin >> calculator[i];
    }

    getResult(0,calcArr);

    cout << maxNum << endl << minNum;

    return 0;
}
void getResult(int index, char calcArr[]) {
    if (index == N-1) {
        int resultNum = numArr[0];
        for (int i=0; i<N-1; i++) {
            if (calcArr[i] == '+') {
                resultNum += numArr[i+1];
            } else if (calcArr[i] == '-') {
                resultNum -= numArr[i+1];
            } else if (calcArr[i] == '*') {
                resultNum *= numArr[i+1];
            } else {
                resultNum /= numArr[i+1];
            }
        }
        if (resultNum > maxNum)
            maxNum = resultNum;
        if (resultNum < minNum)
            minNum = resultNum;
        return;
    }

    if (calculator[0] > 0) {
        calculator[0] -= 1;
        calcArr[index] = '+';
        getResult(index+1, calcArr);
        calculator[0] += 1;
    }
    if (calculator[1] > 0) {
        calculator[1] -= 1;
        calcArr[index] = '-';
        getResult(index+1, calcArr);
        calculator[1] += 1;
    }
    if (calculator[2] > 0) {
        calculator[2] -= 1;
        calcArr[index] = '*';
        getResult(index+1, calcArr);
        calculator[2] += 1;
    }
    if (calculator[3] > 0) {
        calculator[3] -= 1;
        calcArr[index] = '/';
        getResult(index+1, calcArr);
        calculator[3] += 1;
    }
}
