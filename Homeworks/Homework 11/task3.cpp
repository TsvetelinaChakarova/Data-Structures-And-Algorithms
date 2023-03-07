#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

static const int max_size = 1000000;
vector<pair<int, int>> graph[max_size];
int result[max_size];

void dijkstra(int start, int numberOfVertices, vector<int> requests) {
    for (int i = 0; i < numberOfVertices; i++) {
        result[i] = INT_MAX;
    }
    result[start] = 0;

    set<pair<int, int>> current;
    current.insert(make_pair(0, start));

    while (current.size() > 0) {
        int i = (*current.begin()).second;
        current.erase(current.begin());

        for (int j = 0; j < graph[i].size(); j++) {
            if (result[graph[i][j].first] > result[i] + graph[i][j].second) {
                current.erase(make_pair(result[graph[i][j].first], graph[i][j].first));
                result[graph[i][j].first] = result[i] + graph[i][j].second;
                current.insert(make_pair(result[graph[i][j].first], graph[i][j].first));
            }
        }
    }
    
   for (int i = 0; i < requests.size(); i++) {
        printf("%d\n", result[requests[i]]);
   }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numberOfVertices, numberOfEdges;
    int start, end, weight;
    vector<int> T;

    cin >> numberOfVertices;
    cin >> numberOfEdges;

    for (int i = 0; i < numberOfEdges; i++) {
        cin >> start >> end >> weight;
        graph[start].push_back(make_pair(end, weight));
        graph[end].push_back(make_pair(start, weight));
    }

    int numberOfElementsInT, t;
    cin >> numberOfElementsInT;
    for (int i = 0; i < numberOfElementsInT; i++) {
        cin >> t;
        graph[t].push_back(make_pair(numberOfVertices, 0));
        graph[numberOfVertices].push_back(make_pair(t, 0));
        T.push_back(t);
    }

    int numberOfRequests;
    int currentRequest;
    vector<int> requests;
    cin >> numberOfRequests;
    for (int i = 0; i < numberOfRequests; i++) {
        cin >> currentRequest;
        requests.push_back(currentRequest);
    }
    
    dijkstra(numberOfVertices, numberOfVertices, requests);

    return 0;
}
