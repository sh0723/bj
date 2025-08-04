#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string input;
    cin >> input;

    vector<int> numbers;
    vector<char> operators;

    string num = "";

    for (char ch : input) {
        if (ch == '+' || ch == '-') {
            numbers.push_back(stoi(num));
            num = "";
            operators.push_back(ch);
        } else {
            num += ch;
        }
    }
    numbers.push_back(stoi(num));

    int output = numbers[0];
    int operators_count = 0;
    bool minus_valid = true;

    for (size_t i = 1; i < numbers.size(); i++) {
        if (operators[operators_count] == '-' && minus_valid) {
            output -= numbers[i];
            minus_valid = false;
            operators_count++;
            continue;
        }

        if (operators[operators_count] == '-' && !minus_valid) {
            output -= numbers[i];
            operators_count++;
            continue;
        }

        if (operators[operators_count] == '+' && minus_valid) {
            output += numbers[i];
            operators_count++;
            continue;
        }

        if (operators[operators_count] == '+' && !minus_valid) {
            output -= numbers[i];
            operators_count++;
            continue;
        }
    }

    cout << output << endl;

    return 0;
}