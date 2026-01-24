#include <iostream>
using namespace std;

int a,b,c;

long long int run(int num) {
    if (num == 1)
        return a % c;

    long long int result = run(num / 2);
    if (num % 2 == 0) {
        return result * result % c;
    }
    return result * result % c * a % c;
}

int main() {
    cin >> a >> b >> c;

    cout << run(b) << endl;
}
