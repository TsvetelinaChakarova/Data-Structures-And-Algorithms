#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int numberOfTopics, numberOfTeams;
    vector<long long int> topics, teams;
    long long int current;

    cin >> numberOfTopics;
    cin >> numberOfTeams;

    for (int i = 0; i < numberOfTopics; i++) {
        cin >> current;
        topics.push_back(current);
    }

    for (int i = 0; i < numberOfTeams; i++) {
        cin >> current;
        teams.push_back(current);
    }

    sort(topics.begin(), topics.end());

    int position;
    for (int i = 0; i < teams.size(); i++) {

        position = lower_bound(topics.begin(), topics.end(), teams[i]) - topics.begin();

        if (position == -1 || position == 0) cout << topics[0] << endl;
        else {
            if (position == topics.size()) cout << topics[topics.size() - 1] << endl;
            else {
                if (topics[position] == teams[i]) cout << topics[position] << endl;
                else {
                    if (teams[i] > topics[position - 1] && teams[i] < topics[position]) {
                        long double diffToPrevious = teams[i] - topics[position - 1];
                        long double diffToNext = topics[position] - teams[i];
                        if (diffToNext < diffToPrevious) cout << topics[position] << endl;
                        else cout << topics[position - 1] << endl;
                    }
                }
            }
        }
    }
    return 0;
}
