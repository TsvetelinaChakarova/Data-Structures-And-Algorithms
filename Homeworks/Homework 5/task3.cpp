#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int currentNumber, N, d;
    long long int sum = 0;
    vector<int> numbers;
    deque<int> minElements;

    cin >> N;
    cin >> d;

    for (int i = 0; i < N; i++) {
        cin >> currentNumber;
        numbers.push_back(currentNumber);
    }

    for (int i = 0; i < d; i++) {
        while ((!minElements.empty()) && numbers[i] <= numbers[minElements.back()]) {
            minElements.pop_back();
        }
        minElements.push_back(i);
    }

    for (int i = d ; i < N; i++) {
        sum += numbers[minElements.front()];

        while ((!minElements.empty()) && minElements.front() <= i - d) {
            minElements.pop_front();
        }
   
        while ((!minElements.empty()) && numbers[i] <= numbers[minElements.back()]) {
            minElements.pop_back();
        }

        minElements.push_back(i);
    }

    sum += numbers[minElements.front()];

    printf("%lld", sum);

    return 0;
}
