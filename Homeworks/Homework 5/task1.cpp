#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printIndexesOfUniqueElements(string input) {

    vector<pair<long long int, long long int>> countingArray(256);

    for (int i = 0; i < 256; i++) {
        countingArray[i].first = 0;
        countingArray[i].second = -1;
    }

    for (int i = 0; i < input.size(); i++) {
        countingArray[input[i]].first++;
        countingArray[input[i]].second = i;
    }

    sort(countingArray.begin(), countingArray.end(), [](auto& x, auto& y) {
        return x.second < y.second;
        });

    for (int i = 0; i < countingArray.size(); i++) {
        if (countingArray[i].first == 1) {
            printf("%lld ", countingArray[i].second);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

  
    string input;

    cin >> input;
  

    printIndexesOfUniqueElements(input);

    return 0;
}
