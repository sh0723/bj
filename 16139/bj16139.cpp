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
        cin >> n;

        vector<tuple<int,int,char>> vector_to_output(n);

        char target;
        int st_index, end_index;

        vector<vector<int>> count('z'-'a' + 1, vector<int>(string_size, 0));

        for (int i=0; i<n; i++) {
            cin >> target >> st_index >> end_index;
            vector_to_output[i] = make_tuple(st_index, end_index, target);
        }

        for (char c='a'; c<='z'; c++) {
            if (input_string[0] == c) {
                count[c-'a'][0] = 1;
            }
            for (int i=1; i<string_size; i++) {
                if (input_string[i] == c) {
                    count[c-'a'][i] = count[c-'a'][i-1] + 1;
                } else {
                    count[c-'a'][i] = count[c-'a'][i-1];
                }
            }
        }

        for (int i=0; i<n; i++) {
            target = get<2>(vector_to_output[i]);
            st_index = get<0>(vector_to_output[i]);
            end_index = get<1>(vector_to_output[i]);

            if (st_index == 0) {
                cout << count[target-'a'][end_index] << '\n';
            } else {
                cout << count[target-'a'][end_index] - count[target-'a'][st_index-1] << '\n';
            }
        }



        return 0;
    }

/*
 미리 a~z에 해당하는 누적개수에 대한 vector를 만들어놓음으로써 시간을 단축시킴.
 */