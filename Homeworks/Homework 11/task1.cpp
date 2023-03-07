#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

static const int max_size = 1000000;

vector<pair<long long int, long long int>> graph[max_size];
long long int result[max_size];
long long int numberOfPaths[max_size];

void findShortestPaths(int start, int numberOfVertices) {
    for (int i = 0; i < numberOfVertices; i++) {
        result[i] = LLONG_MAX;
        numberOfPaths[i] = 0;
    }
    
    result[start] = 0;
    numberOfPaths[start] = 1;

    set<pair<long long int, long long int>> current;
    current.insert(make_pair(0, start));

    while (current.size() > 0) {
        int i = (*current.begin()).second;
        current.erase(current.begin());

        for (int j = 0; j < graph[i].size(); j++) {
           if (result[graph[i][j].first] >= result[i] + graph[i][j].second) {
                if (result[graph[i][j].first] == result[i] + graph[i][j].second) {
                    numberOfPaths[graph[i][j].first] += numberOfPaths[i];
                    if ( numberOfPaths[graph[i][j].first] >= INT_MAX) {
                            numberOfPaths[graph[i][j].first] %= 1000000007;
                    }
                }
               
                else {
                    current.erase(make_pair(result[graph[i][j].first], graph[i][j].first));
                    numberOfPaths[graph[i][j].first] = numberOfPaths[i] % 1000000007;
                    result[graph[i][j].first] = result[i] + graph[i][j].second;
                    current.insert(make_pair(result[graph[i][j].first], graph[i][j].first));
               }
           }
        }
    }
}

int main() {
    int numberOfVertices, numberOfEdges;
    int start, end, weight;
    vector<pair<pair<int, int>, int>> edges;

    cin >> numberOfVertices;
    cin >> numberOfEdges;
    for (int i = 0; i < numberOfEdges; i++) {
        cin >> start >> end >> weight;
        edges.push_back(make_pair(make_pair(start - 1, end - 1), weight));
    }

    for (int i = 0; i < edges.size(); i++) {
        graph[edges[i].first.first].push_back(make_pair(edges[i].first.second, edges[i].second));
    }

    findShortestPaths(0, numberOfVertices);

    if (result[numberOfVertices - 1] == LLONG_MAX) {
        cout << -1 << " " << 0;
    }
    else {
        cout << result[numberOfVertices - 1] << " " << numberOfPaths[numberOfVertices - 1] % 1000000007;
    }

    return 0;
}
