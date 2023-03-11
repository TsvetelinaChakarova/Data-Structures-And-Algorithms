#include <iostream>
#include <vector>

using namespace std;

static const int MAX_SIZE = 1000000;
int parent[MAX_SIZE];

struct Edge {
    int from;
    int to;
};

int find(int x) {
    if (x == parent[x]) {
        return x;
    }
    else {
        return find(parent[x]);
    }
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        parent[y] = x;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numberOfVertices, numberOfEdges;
    int start, end;
    vector<Edge> edges;

    cin >> numberOfVertices;
    for (int i = 0; i < numberOfVertices; i++) {
       parent[i] = i;
    }
    
    cin >> numberOfEdges;
    for (int i = 0; i < numberOfEdges; i++) {
        cin >> start >> end;
        edges.push_back(Edge{ start, end });
        unite(start, end);
    }

    int numberOfRequests;
    int type, first, second;
    cin >> numberOfRequests;
    for (int i = 0; i < numberOfRequests; i++) {
        cin >> type >> first >> second;
        if (type == 1) {
            if (find(first) == find(second)) {
                cout << 1;
            }
            else {
                cout << 0;
            }
        }
        else {
            unite(first, second);
        }
    }

    return 0;
}
