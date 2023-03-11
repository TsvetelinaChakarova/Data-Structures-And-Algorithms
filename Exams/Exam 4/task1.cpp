#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct task {
    int possibleStartTime;
    int lengthTime;
};

struct Compare {
    bool operator()(task const& x, task const& y)
    {
            return x.possibleStartTime > y.possibleStartTime;
    }
};

struct Compare2 {
    bool operator()(task const& x, task const& y)
    {
        
            return x.lengthTime > y.lengthTime;
        }
       
    
};

int main() {
    vector<pair<long long int, long long int>> IndexAndResutls;
    int numberOfRequests;
    int currentLengthTime;
    long long int currentTime;
    long long int waitingTime = 0;
    priority_queue<task, vector<task>, Compare> possibleStartAndLengthTime;
    priority_queue<task, vector<task>, Compare2> possibleStartAndLengthTime2;

    cin >> numberOfRequests;

    for (int i = 0; i < numberOfRequests; i++) {
        cin >> currentLengthTime;
        possibleStartAndLengthTime.push(task{ i, currentLengthTime});
    }

    currentTime = (long long int)possibleStartAndLengthTime.top().possibleStartTime;

    while (possibleStartAndLengthTime.size() > 0) {
        while (possibleStartAndLengthTime.size() > 0 && possibleStartAndLengthTime.top().possibleStartTime <= currentTime) {
            possibleStartAndLengthTime2.push(possibleStartAndLengthTime.top());
            possibleStartAndLengthTime.pop();
        }

        if (possibleStartAndLengthTime2.size() > 0) {
            long long int currentWait = currentTime - possibleStartAndLengthTime2.top().possibleStartTime + possibleStartAndLengthTime2.top().lengthTime;
            IndexAndResutls.push_back(make_pair(currentWait, possibleStartAndLengthTime2.top().possibleStartTime));
            waitingTime += currentWait;
            currentTime += possibleStartAndLengthTime2.top().lengthTime;
            possibleStartAndLengthTime2.pop();
        }
        
        else {
            currentTime = (long long int)possibleStartAndLengthTime.top().possibleStartTime;
        }
    }

    while (possibleStartAndLengthTime2.size() > 0) {
        long long int currentWait = currentTime - possibleStartAndLengthTime2.top().possibleStartTime + possibleStartAndLengthTime2.top().lengthTime;
        IndexAndResutls.push_back(make_pair(currentWait, possibleStartAndLengthTime2.top().possibleStartTime));
        waitingTime += currentWait;
        currentTime += possibleStartAndLengthTime2.top().lengthTime;
        possibleStartAndLengthTime2.pop();
    }

    cout << (*min_element(IndexAndResutls.begin(), IndexAndResutls.end())).first << " " 
         << (*max_element(IndexAndResutls.begin(), IndexAndResutls.end())).first;

    return 0;
}
