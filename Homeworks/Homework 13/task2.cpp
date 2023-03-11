#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 1000000;
vector <int> graph[MAX_SIZE];
int numberEdgesFromVertice[MAX_SIZE];

int main() {
    int numberOfVertices; 
    int first, second;

    cin >> numberOfVertices;
 
    for (int i = 0; i < numberOfVertices - 1; i++) {
        cin >> first >> second;
        graph[first].push_back(second);    
        graph[second].push_back(first);    
        numberEdgesFromVertice[first]++;
        numberEdgesFromVertice[second]++;
    }

    vector<int> result;

    for (int i = 0; i < numberOfVertices; i++) {
        if (numberEdgesFromVertice[i] == 1) {
            result.push_back(i);
        }
    }

    while (numberOfVertices >= 3) {
        int size = result.size();
        numberOfVertices = numberOfVertices - size;

        for (int i = 0; i < size; i++) {
            int front = result[0];
            result.erase(result.begin());

            for (int j = 0; j < graph[front].size(); j++) {
                numberEdgesFromVertice[graph[front][j]]--;
                if (numberEdgesFromVertice[graph[front][j]] == 1) {
                    result.push_back(graph[front][j]);
                }
            }
        }
    }
    
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}
