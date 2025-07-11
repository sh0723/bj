#include <iostream>
using namespace std;
int cntRecursive;
int fibonacci(int n) {
    if (n == 1  || n == 2) {
        cntRecursive++;
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
int main() {
    int n;
    cin >> n;
    fibonacci(n);
    cout << cntRecursive << " " << n-2;

    return 0;
}