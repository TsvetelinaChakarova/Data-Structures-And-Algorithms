#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct task {
    int possibleStartTime;
    int lengthTime;
    int index;
};

struct Compare {
    bool operator()(task const& x, task const& y)
    {
        if (x.possibleStartTime != y.possibleStartTime) {
            return x.possibleStartTime > y.possibleStartTime;
        }
        else {
            return x.index > y.index;    
        }
    }
};

struct Compare2 {
    bool operator()(task const& x, task const& y)
    {
        if (x.lengthTime != y.lengthTime) {
            return x.lengthTime > y.lengthTime;
        }
        else {
            return x.index > y.index;   
        }
    }
};

int main() {
    int numberOfTasks;
    int currentPossibleStartTime, currentLengthTime;
    long long int currentTime;
    priority_queue<task, vector<task>, Compare> possibleStartAndLengthTime;
    priority_queue<task, vector<task>, Compare2> possibleStartAndLengthTime2;

    cin >> numberOfTasks;
    for (int i = 0; i < numberOfTasks; i++) {
        cin >> currentPossibleStartTime;
        cin >> currentLengthTime;
        possibleStartAndLengthTime.push(task{ currentPossibleStartTime, currentLengthTime, i });
    }

    currentTime = (long long int)possibleStartAndLengthTime.top().possibleStartTime;

    while (possibleStartAndLengthTime.size() > 0) {
        while (possibleStartAndLengthTime.size() > 0 && possibleStartAndLengthTime.top().possibleStartTime <= currentTime) {
            possibleStartAndLengthTime2.push(possibleStartAndLengthTime.top());
            possibleStartAndLengthTime.pop();
        }

        if (possibleStartAndLengthTime2.size() > 0) {
            printf("%d ", possibleStartAndLengthTime2.top().index);
            currentTime += possibleStartAndLengthTime2.top().lengthTime;
            possibleStartAndLengthTime2.pop();
        }
        else {
          currentTime = (long long int)possibleStartAndLengthTime.top().possibleStartTime;
        }
    }

    while (possibleStartAndLengthTime2.size() > 0) {
        printf("%d ", possibleStartAndLengthTime2.top().index);
        possibleStartAndLengthTime2.pop();
    }
    
    return 0;
}
