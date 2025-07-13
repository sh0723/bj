    #include <iostream>
    #include <vector>

    using namespace std;

    int main() {

        int N, K;

        cin >> N >> K;

        vector<int> coin(N);

        for (int i = 0; i < N; i++) {
            cin >> coin[i];
        }

        int count = 0;

        for (int i=N-1; i>=0; i--) {
            if (K % coin[i] == K)
                continue;
            else {
                count += (K / coin[i]);
                K %= coin[i];
            }
        }

        cout << count << endl;


        return 0;
    }