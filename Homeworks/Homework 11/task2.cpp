#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

static const int max_size = 10000;
vector<pair<int, pair<int, int>>> graph[max_size];
int result[max_size];

void dijkstra(int currentKgs, int numberOfVertices) {
    for (int i = 0; i < numberOfVertices; i++) {
        result[i] = INT_MAX;
    }
    result[0] = 0;

    set<pair<int, int>> current;
    current.insert(make_pair(0, 0));

    while (current.size() > 0) {
        int i = (*current.begin()).second;
        current.erase(current.begin());

        for (int j = 0; j < graph[i].size(); j++) {
            if (currentKgs >= graph[i][j].second.first) {
                if (result[graph[i][j].first] > result[i] + graph[i][j].second.second) {
                    current.erase(make_pair(result[graph[i][j].first], graph[i][j].first));
                    result[graph[i][j].first] = result[i] + graph[i][j].second.second;
                    current.insert(make_pair(result[graph[i][j].first], graph[i][j].first));
                }
            }
        }
    }
}

int binary_search(int left, int right, int numberOfVertices, int maxTime) {
    int searchedKgs = INT_MAX;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        
        dijkstra(middle, numberOfVertices);
        if (result[numberOfVertices-1] <= maxTime) {
            if (searchedKgs == INT_MAX) {
                searchedKgs = middle;
            }

            if (middle < searchedKgs) {
                searchedKgs = middle;
            }
      
            right = middle - 1;
        }

        else {
            left = middle + 1;
        }
    }

    return searchedKgs;
}

int main() {
    int numberOfVertices, numberOfEdges, maxTime;
    int start, end, kg, time;
    set<int> kgs;

    cin >> numberOfVertices;
    cin >> numberOfEdges;
    cin >> maxTime;
    for (int i = 0; i < numberOfEdges; i++) {
        cin >> start >> end >> kg >> time;
        graph[start-1].push_back(make_pair(end-1, make_pair(kg, time)));
        kgs.insert(kg);
    }

    if (binary_search(0, *kgs.rbegin(), numberOfVertices, maxTime) == INT_MAX) {
        cout << -1 << endl;
    }
    else {
        cout << binary_search(0, *kgs.rbegin(), numberOfVertices, maxTime) << endl;
    }

    return 0;
}
