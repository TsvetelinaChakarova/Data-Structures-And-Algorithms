#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int lengthOfLongestIncreasingSubsequenceByFirst(vector<pair<int, int>>& array) {
    vector<int> longestIncreasingSubsequence;
    longestIncreasingSubsequence.push_back(array[0].first);
    for (int i = 1;i < array.size();i++) {
        if (longestIncreasingSubsequence.back() < array[i].first)
            longestIncreasingSubsequence.push_back(array[i].first);
        else {
            int in = lower_bound(longestIncreasingSubsequence.begin(), longestIncreasingSubsequence.end(), array[i].first) - longestIncreasingSubsequence.begin();
            longestIncreasingSubsequence[in] = array[i].first;
        }
    }
    return longestIncreasingSubsequence.size();
}


int lengthOfLongestIncreasingSubsequenceBySecond(vector<pair<int, int>>& array) {
    vector<int> longestIncreasingSubsequence;
    longestIncreasingSubsequence.push_back(array[0].second);
    for (int i = 1;i < array.size();i++) {
        if (longestIncreasingSubsequence.back() < array[i].second)
            longestIncreasingSubsequence.push_back(array[i].second);
        else {
            int in = lower_bound(longestIncreasingSubsequence.begin(), longestIncreasingSubsequence.end(), array[i].second) - longestIncreasingSubsequence.begin();
            longestIncreasingSubsequence[in] = array[i].second;
        }
    }
    return longestIncreasingSubsequence.size();
}

bool sortByFirst(pair<int, int> element1, pair<int, int> element2)
{
    return (element1.first <= element2.first);
}

bool sortBySecond( pair<int, int> element1,  pair<int, int> element2)
{
    return (element1.second <= element2.second);
}

int main() {
    int numberOfDemons, currentDefence, currentAttack;
    vector<pair<int, int>> demons; // defence & attack

    cin >> numberOfDemons;
    for (int i = 0; i < numberOfDemons; i++) {
        cin >> currentDefence >> currentAttack;
        demons.push_back(make_pair(currentDefence, currentAttack));
    }

    int defeatedDeamons1, defeatedDemons2;
    sort(demons.begin(), demons.end(), sortBySecond);
    defeatedDeamons1 = lengthOfLongestIncreasingSubsequenceByFirst(demons);

    sort(demons.begin(), demons.end(), sortByFirst);
    defeatedDemons2 = lengthOfLongestIncreasingSubsequenceBySecond(demons);
   
    if (defeatedDeamons1 > defeatedDemons2) {
        cout << defeatedDeamons1 << endl;
    }
    else {
        cout << defeatedDemons2 << endl;
    }

    return 0;
}
