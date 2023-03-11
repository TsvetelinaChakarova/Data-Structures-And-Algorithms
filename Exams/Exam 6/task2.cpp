#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> graph[1000000];
vector<bool> visited;

void dfs(int v) {
    visited[v] = true;
    
    for (auto x : graph[v]) {
        if (visited[x] == false) {
            dfs(x);
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m, start, end;
        cin >> n >> m;
        for (int j = 0; j < m; j++) {
            cin >> start >> end;
            graph[start].push_back(end);
            graph[end].push_back(start);
        }
        
        int components = 0; 
        for (int j = 0; j < n; j++) {
            visited.push_back(0);
        }
        for (int j = 0; j < n; j++) {
            if (visited[j] == false) {
                dfs(j);
                components++;
            }
        }
        cout << components<< " ";
        
        visited.clear();
        for (int j = 0; j < n; j++)
            graph[j].clear();
        
    }
    return 0;
}
