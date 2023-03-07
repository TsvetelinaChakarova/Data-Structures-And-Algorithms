#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    unsigned long numberOfNumbers;
    int number;
    bool isThereAnswer = false;
    vector <int> numbers;

    cin >> numberOfNumbers;

    for (int i = 0; i < numberOfNumbers; i++) {
        cin >> number;
        if (number > 0) {
            numbers.push_back(number);
        }
    }

    if (numbers.size() == 0) {
        cout << 1 << endl;
    }

    else {
        sort(numbers.begin(), numbers.end());
        if (numbers[0] != 1) {
            cout << 1 << endl;
            isThereAnswer = true;
        }

        else {
            for (int i = 1; i < numbers.size(); i++) {
                if (numbers[i] - numbers [i-1] != 1 && numbers[i] - numbers[i-1] != 0) {
                    cout << numbers[i-1] + 1 << endl;
                    isThereAnswer = true;
                    break;
                }
            }
        }

        if (isThereAnswer == false) {
            cout << numbers[numbers.size() -  1] + 1 << endl;
        }
    }

    return 0;
}
