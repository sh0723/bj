#include<iostream>
#include <vector>
using namespace std;
int main() {

    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> upper_arr(n,1);
    vector<int> lower_arr(n,1);

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int max = 1;
    for (int i=0; i<n; i++) {
        for (int j=i; j>=0; j--) {
            if (arr[i] > arr[j] && max < (upper_arr[j] + 1)) {
                upper_arr[i] = upper_arr[j] + 1;
                max = upper_arr[i];
            }
        }
        max = 1;
    }

    max = 1;
    for (int i=n-1; i>=0; i--) {
        for (int j=i; j<n; j++) {
            if (arr[i] > arr[j] && max < (lower_arr[j] + 1)) {
                lower_arr[i] = lower_arr[j] + 1;
                max = lower_arr[i];
            }
        }
        max = 1;
    }

    max = 0;
    for (int i=0; i<n; i++) {
        if (upper_arr[i] + lower_arr[i] > max) {
            max = upper_arr[i] + lower_arr[i];
        }
    }

    cout << max-1;

    return 0;
}