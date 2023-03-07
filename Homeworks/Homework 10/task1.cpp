#include <iostream>
#include <vector>

using namespace std;

vector<int> requests[1000000];
int visited[1000000];

bool isThereCycleContainingX(int x) {
    visited[x] = 1;

    for (int i = 0; i < requests[x].size(); i++) {
        if (visited[requests[x][i]] == 0) {
            if (isThereCycleContainingX(requests[x][i]) == true) {
                return true;
            }
        }
        else {
            if (visited[requests[x][i]] == 1) {
                return true;
            }
        }
    }
    
    visited[x] = -1;
    return false;
}

int main()
{
    int numberOfRequests;
    int numberOfEdges;
    int start, end;

    cin >> numberOfRequests;
    for (int i = 0; i < numberOfRequests; i++) {
        cin >> numberOfEdges;
        
        for (int i = 0; i < 1000000; i++)
            visited[i] = 0;
        
        vector<pair<int, int>> edges;

        for (int j = 0; j < numberOfEdges; j++) {
            cin >> start;
            cin >> end;
            edges.push_back(make_pair(start, end));
        }

        for (int j = 0; j < numberOfEdges; j++) {
            requests[edges[j].first].push_back(edges[j].second);
        }

        bool isThereCycle = false;
        for (int j = 0; j < numberOfEdges; j++) {
            if (isThereCycleContainingX(edges[j].first) == true) {
                isThereCycle = true;
            }
            if (isThereCycleContainingX(edges[j].second) == true) {
                isThereCycle = true;
            }
        }

        cout << isThereCycle << " ";
        
        requests->clear();
        for (int i = 0; i < 1000000; i++) {
         requests[i].clear();
        }
        edges.clear();
    
    }

    return 0;
}
