#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> resultNum(n+1);
    resultNum[0] = 0;
    resultNum[1] = 9;
    resultNum[2] = 17;
    for (int i=3; i<=n; i++) {
        resultNum[i] = (resultNum[i-1] - 1 ) * 2;
    }

    cout << resultNum[n];

    return 0;
}
/*
 f(1) = 9
 f(2) = (f(1) - 1) * 2 + 1
 f(3) =

1 2 3 4 5 6 7 8 9

   12 23 34 45 56 67 78 89
 + 21 32 43 54 65 76 87 98 10
 17개 - > 2개

 121 123 / 234 232  / 343 345 /  456 454 / 565 567 /  678 676  / 789 787 / 898
 212 210 / 321 323 / 432 434 /  545 543 / 656 654 /  767 765  / 876 878 / 987 989
 101


 32개 - > 짝에서 홀로 갈 땐 +1 아닐땐 *2

 */