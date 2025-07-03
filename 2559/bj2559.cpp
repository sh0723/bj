#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, period;

    cin >> n >> period;
    vector<int> input_arr(n);
    vector<int> sum_arr(n+1,0);
    vector<int> output_arr(n-period+1);

    for (int i=0; i<n; i++) {
        cin >> input_arr[i];
    }

    for (int i=1; i<=n; i++) {
        sum_arr[i] = sum_arr[i-1] + input_arr[i-1];
    }

    for (int i=period-1; i<n; i++) {
        output_arr[i-period+1] = sum_arr[i+1] - sum_arr[i-period+1];
    }

    int max = output_arr[0];

    for (int i=1; i<n-period+1; i++) {
        if (output_arr[i] > max) {
            max = output_arr[i];
        }
    }

    cout << max << endl;

    return 0;
}