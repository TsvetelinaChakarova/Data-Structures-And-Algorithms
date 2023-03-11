#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 1000;

vector <int> graph[MAX_SIZE];
bool visited[MAX_SIZE];
int parent[MAX_SIZE];
int numberOfPaths = 0;

void findNumberOfPaths(int current, int size, int numberOfVertices)
{
    if (size == numberOfVertices) {
        if (current == numberOfVertices - 1) {
            numberOfPaths++;
        }
       
        while (current != -1) {
            current = parent[current];
        }

        return;
    }

    visited[current] = 1;

    for (auto next : graph[current])
    {
        if (!visited[next]) {

            parent[next] = current;

            findNumberOfPaths(next, size + 1, numberOfVertices);
        }
    }

    visited[current] = 0;
}

int main() {
    int rows, cols;
    char current;
    int lab[26][26];
    int verticeNumber = 1, startVerticeNumber, endVerticeNumber;
    int iEnd, jEnd;
   
    cin >> rows >> cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> current;
            if (current == '-') {
                lab[i][j] = verticeNumber;
                verticeNumber++;
            }
            if (current == 's') {
                lab[i][j] = 0;
 
            }
            if (current == 'e') {
                iEnd = i;
                jEnd = j;

            }
            if (current == 'x')
                lab[i][j] = -1;
        }
    }


    lab[iEnd][jEnd] = verticeNumber;
    int numberOfVertices = lab[iEnd][jEnd] + 1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (lab[i][j] != -1) {
                if (i == 0 && j == 0 && i+1 < rows && j+1 < cols) {
                    if (lab[i + 1][j] != -1) { graph[lab[i][j]].push_back(lab[i + 1][j]); }
                    if (lab[i][j + 1] != -1) { graph[lab[i][j]].push_back(lab[i][j + 1]); }
                }

                if (i == 0 && j == cols - 1 && i+1 < rows && j - 1 >= 0) {
                    if (lab[i + 1][j] != -1) { graph[lab[i][j]].push_back(lab[i + 1][j]); }
                    if (lab[i][j - 1] != -1) { graph[lab[i][j]].push_back(lab[i][j - 1]); }
                }

                if (i == rows - 1 && j == 0 && j + 1 < cols && i - 1 >= 0) {
                    if (lab[i - 1][j] != -1) { graph[lab[i][j]].push_back(lab[i - 1][j]); }
                    if (lab[i][j + 1] != -1) { graph[lab[i][j]].push_back(lab[i][j + 1]); }
                }

                if (i == rows - 1 && j == cols - 1 && i - 1 >= 0 && j - 1 >= 0) {
                    if (lab[i - 1][j] != -1) { graph[lab[i][j]].push_back(lab[i - 1][j]); }
                    if (lab[i][j - 1] != -1) { graph[lab[i][j]].push_back(lab[i][j - 1]); }
                }

                if (i != 0 && i != rows - 1 && j == 0 && j + 1 < cols) {
                    if (lab[i - 1][j] != -1) { graph[lab[i][j]].push_back(lab[i - 1][j]); }
                    if (lab[i + 1][j] != -1) { graph[lab[i][j]].push_back(lab[i + 1][j]); }
                    if (lab[i][j + 1] != -1) { graph[lab[i][j]].push_back(lab[i][j + 1]); }
                }

                if (i != 0 && i != rows - 1 && j == cols - 1 && j - 1 >= 0) {
                    if (lab[i - 1][j] != -1) { graph[lab[i][j]].push_back(lab[i - 1][j]); }
                    if (lab[i + 1][j] != -1) { graph[lab[i][j]].push_back(lab[i + 1][j]); }
                    if (lab[i][j - 1] != -1) { graph[lab[i][j]].push_back(lab[i][j - 1]); }
                }

                if (i == 0 && j != 0 && j != cols - 1 && i + 1 < rows) {
                    if (lab[i][j + 1] != -1) { graph[lab[i][j]].push_back(lab[i][j + 1]); }
                    if (lab[i][j - 1] != -1) { graph[lab[i][j]].push_back(lab[i][j - 1]); }
                    if (lab[i + 1][j] != -1) { graph[lab[i][j]].push_back(lab[i + 1][j]); }
                }

                if (i == rows - 1 && j != 0 && j != cols - 1 && i - 1 >= 0) {
                    if (lab[i][j + 1] != -1) { graph[lab[i][j]].push_back(lab[i][j + 1]); }
                    if (lab[i][j - 1] != -1) { graph[lab[i][j]].push_back(lab[i][j - 1]); }
                    if (lab[i - 1][j] != -1) { graph[lab[i][j]].push_back(lab[i - 1][j]); }
                }

                if (i != 0 && i != rows - 1 && j != 0 && j != cols - 1) {
                    if (lab[i][j + 1] != -1) { graph[lab[i][j]].push_back(lab[i][j + 1]); }
                    if (lab[i][j - 1] != -1) { graph[lab[i][j]].push_back(lab[i][j - 1]); }
                    if (lab[i + 1][j] != -1) { graph[lab[i][j]].push_back(lab[i + 1][j]); }
                    if (lab[i - 1][j] != -1) { graph[lab[i][j]].push_back(lab[i - 1][j]); }
                }

                
                if (i == 0 && j == 0 && i + 1 < rows && j + 1 >= cols) {
                    if (lab[i + 1][j] != -1) { graph[lab[i][j]].push_back(lab[i + 1][j]); }
                }

                if (i == rows - 1 && j == 0 && j + 1 >= cols && i - 1 >= 0) {
                    if (lab[i - 1][j] != -1) { graph[lab[i][j]].push_back(lab[i - 1][j]); }
                }

                if (i != 0 && i != rows - 1 && j == 0 && j + 1 >= cols) {
                    if (lab[i - 1][j] != -1) { graph[lab[i][j]].push_back(lab[i - 1][j]); }
                    if (lab[i + 1][j] != -1) { graph[lab[i][j]].push_back(lab[i + 1][j]); }
                }
                
                if (i == 0 && j == 0 && i + 1 >= rows && j + 1 < cols) {  
                    if (lab[i][j + 1] != -1) { graph[lab[i][j]].push_back(lab[i][j + 1]); }
                }

                if (i == 0 && j == cols - 1 && i + 1 >=  rows && j - 1 >= 0) {
                    if (lab[i][j - 1] != -1) { graph[lab[i][j]].push_back(lab[i][j - 1]); }
                }

                if (i == 0 && j != 0 && j != cols - 1 && i + 1 >= rows) {
                    if (lab[i][j + 1] != -1) { graph[lab[i][j]].push_back(lab[i][j + 1]); }
                    if (lab[i][j - 1] != -1) { graph[lab[i][j]].push_back(lab[i][j - 1]); }
                }
            }
        }
    }

    parent[0] = -1;
    findNumberOfPaths(0, 1, numberOfVertices);
    cout << numberOfPaths << endl;

    return 0;
}
