#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_SIZE = 1000000;
int numberEdgesFromVertice[MAX_SIZE];
vector<int> graph[MAX_SIZE];
vector<int> visited;

void findNumberOfComponents(int current) {
    if (visited[current] == true) {
        return;
    }
    else {
        visited[current] = true;
        for (int i = 0; i < graph[current].size(); i++) {
            findNumberOfComponents(graph[current][i]);
        }
    }
}

int main() {
    int numberOfRequests;
    int numberOfVertices, numberOfEdges;
    int numberOfOddVertices;
    int first, second;
    set<int> vertices;

    cin >> numberOfRequests;
    for (int i = 0; i < numberOfRequests; i++) {
        numberOfOddVertices = 0;
        int numberOfComponents = 0; 
        
        cin >> numberOfVertices >> numberOfEdges;

        for (int j = 0; j < MAX_SIZE; j++) {
            numberEdgesFromVertice[j] = 0;
        }

        for (int j = 0; j < numberOfEdges; j++) {
            cin >> first >> second;
            graph[first].push_back(second);
            graph[second].push_back(first);
            numberEdgesFromVertice[first]++;
            numberEdgesFromVertice[second]++;
            vertices.insert(first);
            vertices.insert(second);
        }

         for (auto vertice : vertices) {
            if (numberEdgesFromVertice[vertice] % 2 == 1) {
                numberOfOddVertices++;
            }
            visited.push_back(false);
        }

        for (auto vertice : vertices) {
            if (visited[vertice] == false) {
                findNumberOfComponents(vertice);
                numberOfComponents++;
            }
        }

        if (numberOfComponents != 1 || vertices.size() != numberOfVertices) {
            cout << "none" << endl;
        }
        else {
            if (numberOfOddVertices != 2 && numberOfOddVertices != 0) {
                cout << "none" << endl;
            }
            else {
                if (numberOfOddVertices == 2) {
                    cout << "epath" << endl;
                }
                else {
                    cout << "ecycle" << endl;
                }
            }
        }

        graph->clear();
        for (int i = 0; i < MAX_SIZE; i++) {
            graph[i].clear();
        }
        
        visited.clear();
        vertices.clear();
    }

    return 0;
}
