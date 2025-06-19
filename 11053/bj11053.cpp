#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {

    int num;
    cin >> num;
    vector<int> arr(num);

    for (int i = 0; i < num; i++) {
        int temp_num;
        cin >> temp_num;
        arr[i] = temp_num;
    }

    vector<int> max_len(num, 1);
    for (int i=0; i<num; i++) {
        for (int j=i-1; j>=0; j--) {
            if (arr[i] > arr[j]) {
                max_len[i] = max(max_len[i], max_len[j]+1);
            }
        }
    }

    int max_num = 1;
    for (int i=0; i<num; i++) {
        max_num = max(max_num, max_len[i]);
    }
    cout << max_num << endl;
}

/*
 i=0 ~ n-1까지 돌리며
 0각각 내부적으로 i~0까지 돌리며 자기보다 작은게 나오면 멈춰 그리고 그거에 +1을 자기 값으로 갖음
 */