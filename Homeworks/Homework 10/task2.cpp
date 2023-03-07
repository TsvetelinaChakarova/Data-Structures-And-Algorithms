#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    set<pair<int, int>> illPeople;
    
    int rows, cols;
    int movieLength;
    int numberOfillStudents;
    
    cin >> rows >> cols;
    cin >> movieLength;
    cin >> numberOfillStudents;
    int currentI, currentJ;
    for (int i = 0; i < numberOfillStudents; i++) {
        cin >> currentI >> currentJ;
        illPeople.insert(make_pair(currentI-1, currentJ-1));
    }

    for (int i = 0; i < movieLength; i++) {
        set<pair<int, int>> illPeople2 = illPeople;
        for (auto j : illPeople2) {
            if (j.first != rows - 1) {
                illPeople.insert(make_pair(j.first + 1, j.second));
            }
            if (j.first != 0) {
                illPeople.insert(make_pair(j.first - 1, j.second));
            }
            if (j.second != cols - 1) { 
                illPeople.insert(make_pair(j.first, j.second + 1));
            }
            if (j.second != 0) { 
                illPeople.insert(make_pair(j.first, j.second - 1));
            }
        }
    }

    cout << rows*cols - illPeople.size() << endl;

    return 0;
}
