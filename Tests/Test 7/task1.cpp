#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int N;
    vector<int> numbers;
    map<int, int> numberAndTimes;
    vector<int> result;

    int current;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> current;
        numbers.push_back(current);
        numberAndTimes[current]++;
    }

    for (int i = 0; i < numbers.size(); i++) {
        if (numberAndTimes.find(numbers[i])->second == 1) {
            result.push_back(numbers[i]);
            numberAndTimes.find(numbers[i])->second = 0;
        }
    }

    for (int i = 0; i < numbers.size(); i++) {
        if (numberAndTimes.find(numbers[i])->second != 0) {
            result.push_back(numbers[i]);
            numberAndTimes.find(numbers[i])->second = 0;
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
