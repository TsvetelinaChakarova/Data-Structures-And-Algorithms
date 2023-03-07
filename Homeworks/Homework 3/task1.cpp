#include <vector>
#include <iostream>
using namespace std;

int main() {
    long double numberOfPoints, numberofPresents = 0;
    cin >> numberOfPoints;

    while (numberOfPoints != 0) {
        vector<long double> cubics;
        long double current = 1;
        while (current * current * current <= numberOfPoints) {
            cubics.push_back(current * current * current);
            current++;
        }
        numberOfPoints -= cubics[cubics.size() - 1];
        numberofPresents++;
    }

    cout << numberofPresents << endl;
    return 0;
}
