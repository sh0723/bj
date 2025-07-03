#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main() {

    string s;
    cin >> s;

    vector<char> input_string;

    for (char c : s) {
        input_string.push_back(c);
    }
    int string_size = input_string.size();
    int n;
    vector<tuple<int,int,char>> vector_to_output(n);

    char target;
    int st_index, end_index;

    vector<vector<int>> count('z'-'a' + 1);

    for (int i=0; i<n; i++) {
        cin >> target >> st_index >> end_index;
        vector_to_output[i] = make_tuple(st_index, end_index, target);
        if (count[target-'a'].size() > 0)
            continue;

        count[target-'a'].resize(string_size,0);

        if (input_string[0] == target) {
            count[target-'a'][0] = 1;
        } else {
            count[target-'a'][0] = 0;
        }

        for (int j=1; j<string_size; j++) {

            if (input_string[j] == target) {
                count[target-'a'][j] = count[target-'a'][j-1] + 1;
            } else {
                count[target-'a'][j] = count[target-'a'][j-1];
            }
        }
    }

    for (int i=0; i<n; i++) {
        target = get<2>(vector_to_output[i]);
        st_index = get<0>(vector_to_output[i]);
        end_index = get<1>(vector_to_output[i]);

        cout << count[target-'a'][end_index] - count[target-'a'][st_index] << endl;
    }



    return 0;
}