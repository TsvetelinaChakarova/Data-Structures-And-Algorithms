#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1000000;
vector<int> graph[MAX_SIZE];
vector<int> conectedComponent;

void inWhichComponent(int currentNode, int currentComponent) {
    conectedComponent[currentNode] = currentComponent;
    for (auto x : graph[currentNode]) {
        if (conectedComponent[x] == -1) {
            inWhichComponent(x, currentComponent);
        }
    }
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    int n, m, start, end;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> start >> end;
        graph[end-1].push_back(start-1);
        graph[start-1].push_back(end-1);
    }
    
    for (int i = 0; i < n; i++) {
        conectedComponent.push_back(-1);
    }
    
    int currentComponent = 0;
    for (int i = 0; i < n; i++) {
        if (conectedComponent[i] == -1) {
            currentComponent++;
            inWhichComponent(i, currentComponent);
        }
    }
    
    
    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> start >> end;
        if (conectedComponent[start-1] == conectedComponent[end-1]) {
          printf("%d ", 1);
        }
        else {
            printf("%d ", 0);    
        }
    }
    
    return 0;
}
