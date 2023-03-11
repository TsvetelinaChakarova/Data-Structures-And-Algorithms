#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

static const int MAX_SIZE = 1000000;

struct Edge {
    int from;
    int to;
    int speed;

    bool operator <(const Edge& rhs) const {
        return make_pair(speed, to) < make_pair(rhs.speed, rhs.to);
    }
};

int parent[MAX_SIZE];
int depth[MAX_SIZE];
vector<Edge> edges;

int find(int x) {
    if (x == parent[x]) {
        return x;
    }

    int root = find(parent[x]);
    parent[x] = root;
    return root;
}

void unite(int x, int y) {
    parent[find(x)] = parent[find(y)];
}


void findSpeeds(int numberOfVertices) {
    int finalMaxSpeed = INT_MAX, finalMinSpeed = -1;
    int prevMinSpeed = 0, prevMaxSpeed = INT_MAX;
    int currentMinSPeed, currentMaxSpeed, verticesLeft;

    sort(edges.begin(), edges.end());

    for (int i = 0; i < edges.size(); i++) {
        verticesLeft = numberOfVertices - 1;
        for (int j = 0; j < numberOfVertices + 1; j++) {
            parent[j] = j;
            depth[j] = 0;
        }
        unite(edges[i].from, edges[i].to);

        currentMinSPeed = edges[i].speed;
        currentMaxSpeed = edges[i].speed;
        for (int j = i; j < edges.size(); j++) {
            if (find(edges[j].from) != find(edges[j].to)) {
                unite(edges[j].from, edges[j].to);
                if (edges[j].speed > currentMaxSpeed) {
                    currentMaxSpeed = edges[j].speed;
                }
                verticesLeft--;
            }
        }

        if (verticesLeft == 1 && currentMaxSpeed - currentMinSPeed < prevMaxSpeed - prevMinSpeed) {
            finalMinSpeed = currentMinSPeed;
            finalMaxSpeed = currentMaxSpeed;
            prevMinSpeed = currentMinSPeed;
            prevMaxSpeed = currentMaxSpeed;
        }
    }

    cout << finalMinSpeed << " " << finalMaxSpeed;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numberOfVertices, numberOfEdges;
    int from, to, speed;

    cin >> numberOfVertices;
    cin >> numberOfEdges;
    for (int i = 0; i < numberOfEdges; i++) {
        cin >> from >> to >> speed;
        edges.push_back(Edge{ from, to, speed });
    }

    findSpeeds(numberOfVertices);

    return 0;
}
