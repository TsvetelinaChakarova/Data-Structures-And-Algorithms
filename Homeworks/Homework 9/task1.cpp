#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numberOfDoorsAndKeys;
    int currentDoor, currentKey;
    vector<int> doors;
    vector<int> keys;
    unordered_multiset<int> keys2;
    int numberOfOpenedDoors = 0;

    cin >> numberOfDoorsAndKeys;

    for (int i = 0; i < numberOfDoorsAndKeys; i++) {
        cin >> currentKey;
        keys.push_back(currentKey);

    }

    for (int i = 0; i < numberOfDoorsAndKeys; i++) {
        cin >> currentDoor;
        doors.push_back(currentDoor);

    }

    for (int i = 0; i < numberOfDoorsAndKeys; i++) {
        keys2.insert(keys[i]);

        if (keys2.find(doors[i]) != keys2.end()) {
            numberOfOpenedDoors++;
            keys2.erase(keys2.find(doors[i]));

        }
    }


    printf("%d", numberOfDoorsAndKeys - numberOfOpenedDoors);

    return 0;
}
