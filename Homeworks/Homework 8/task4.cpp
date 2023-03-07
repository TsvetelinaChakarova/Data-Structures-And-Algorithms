#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numberOfCalls, numberOfOperators;
    int currentStartTime, currentLengthTime;
    vector<pair<int, int>> startAndLength;
    vector <int>results;

    cin >> numberOfCalls;
    cin >> numberOfOperators;

    for (int i = 0; i < numberOfCalls; i++) {
        cin >> currentStartTime;
        cin >> currentLengthTime;
        startAndLength.push_back(make_pair(currentStartTime, currentLengthTime));
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> talkingOperators;
    set<int> freeOperators;

    for (int i = 0; i < numberOfOperators; i++) {
        results.push_back(0);
        freeOperators.insert(i);
    }

    for (int i = 0; i < numberOfCalls; i++) {
        while (talkingOperators.size() > 0 && talkingOperators.top().first <= startAndLength[i].first) {
            freeOperators.insert(talkingOperators.top().second);
            talkingOperators.pop();
        }

        if (freeOperators.size() > 0) {
            if (freeOperators.lower_bound(i % numberOfOperators) == freeOperators.end()) {
                talkingOperators.push(make_pair(startAndLength[i].first + startAndLength[i].second,                                                                       *freeOperators.begin()));
                results[*freeOperators.begin()]++;
                freeOperators.erase(*freeOperators.begin());
                
            }
            else {
                talkingOperators.push(make_pair(startAndLength[i].first + startAndLength[i].second, 
                                                *freeOperators.lower_bound(i % numberOfOperators)));
                results[*freeOperators.lower_bound(i % numberOfOperators)]++;
                freeOperators.erase(*freeOperators.lower_bound(i % numberOfOperators));
            }
        }
    }

    int maxTakenCalls = *max_element(results.begin(), results.end());
    for (int i = 0; i < numberOfOperators; i++) {
        if (results[i] == maxTakenCalls) {
            printf("%d ", i);
        }
    }

    return 0;
}
