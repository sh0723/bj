#include <iostream>
#include <vector>
using namespace std;

int main() {

    // 자기한테 담겨있는거---- 그 이후에 자기와 작은거 찾을 때마다 1키로당 드는 비용 업데이트

    int n;
    cin >> n;

    vector <long long int> oil_price(n);
    vector <long long int> distance(n-1);

    for (int i=0; i<n-1; i++) {
        cin >> distance[i];
    }

    for (int i=0; i<n; i++) {
        cin >> oil_price[i];
    }

    long long int current_oil_price = oil_price[0];
    long long int total_oil = 0;
    for (int i=0; i<n-1; i++) {
        total_oil += distance[i] * current_oil_price;
        if (current_oil_price > oil_price[i+1]) {
            current_oil_price = oil_price[i+1];
        }

    }

    cout << total_oil << endl;



    return 0;
}