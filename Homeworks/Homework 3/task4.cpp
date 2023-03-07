#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q, current, current2, chosenNumbersCount, sum;
    vector <int> numbers; //a1, a2 ... 

    cin >> N;
    cin >> Q;
    for (int i = 0; i < N; i++) {
        cin >> current;
        numbers.push_back(current);
    }
    
    sort(numbers.begin(), numbers.end());
    
    for (int i = 0; i < Q; i++) {
      cin >> current; 
      cin >> current2;
     
      sum = 0;
      chosenNumbersCount = 0;
      int position = upper_bound(numbers.begin(), numbers.end(), current2) - numbers.begin() - 1;

      while (position >= 0  && sum + numbers[position] <= current) {
          sum += numbers[position--];
          chosenNumbersCount++;
      }

      printf("%d\n", chosenNumbersCount);

    }

    return 0;
}
