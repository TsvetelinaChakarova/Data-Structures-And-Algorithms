#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const int MAX_SIZE = 1000000;

struct Edge {
    int from;
    int to;
    long long int effort;
    long long int profit;
    int index;

    bool operator <(const Edge& rhs) const {
        if (effort == rhs.effort) {
           return profit > rhs.profit;
        }
        else {
             return effort < rhs.effort;
        }
    }
};

int parent[MAX_SIZE];
int depth[MAX_SIZE];
vector<pair<int, long long int>> result[MAX_SIZE];

int find(int x) {
    if (x == parent[x]) {
        return x;
    }

    int root = find(parent[x]);
    parent[x] = root;
    return root;
}

void unite(int x, int y) {
    if (depth[x] > depth[y]) {
        parent[y] = x;
    }
    else {
        if (depth[y] > depth[x]) {
            parent[x] = y;
        }
        else {
            parent[y] = x;
            depth[x]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numberOfVertices, numberOfEdges;
    vector<Edge> edges;
    int from, to; 
    long long int effort, profit;

    cin >> numberOfVertices;
    cin >> numberOfEdges;
    for (int i = 0; i < numberOfEdges; i++) {
        cin >> from >> to >> effort >> profit;
        edges.push_back(Edge{ from, to, effort, profit , i+1});
    }

    int numberOfComponents = numberOfVertices;
    sort(edges.begin(), edges.end());

    for (int i = 0; i < numberOfVertices; i++) {
        parent[i] = i;
        depth[i] = 0;
    }

    for (int i = 0; i < edges.size(); i++) {
        if (find(edges[i].from) != find(edges[i].to)) {
            unite(find(edges[i].from), find(edges[i].to));
            result[edges[i].from].push_back(make_pair(edges[i].to, edges[i].effort));
            result[edges[i].to].push_back(make_pair(edges[i].from, edges[i].effort));
            numberOfComponents--;
            printf("%d\n", edges[i].index);
        }

        if (numberOfComponents == 1) {
            break;
        }
    }
 
    return 0;
}
