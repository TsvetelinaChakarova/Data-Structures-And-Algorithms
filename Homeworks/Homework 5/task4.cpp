#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long int numberOfPlayers;
    deque<pair<long long int, long long int>> players; // <hunger, index>
    long long int current;

    cin >> numberOfPlayers;
    for (long long int i = 0; i < numberOfPlayers; i++) {
        cin >> current;
        players.push_back(make_pair(current, i));

    }

    long long int numberOfDays = 0;
    bool areThereChanges = true;
    long long int removedElement;
    long long int cycleOfInitializationOfRemovedElement = -2;
    long long int cycle = 0;

    while (players.size() != 1 && areThereChanges != false) {
        areThereChanges = false;
        players.push_back(players.front());
        players.pop_front();
        long long int rightElement;
        cycle = 0;
        while (players.front().second != 0) {

            if (cycleOfInitializationOfRemovedElement != cycle - 1) {
                rightElement = players.back().first;
            }
            else {
                rightElement = removedElement;
            }
            if (players.front().first <= rightElement) {
                players.push_back(players.front());
                players.pop_front();
            }
            else {
                removedElement = players.front().first;
                cycleOfInitializationOfRemovedElement = cycle;
                players.pop_front();
                areThereChanges = true;

            }
            cycle++;
        }

        if (areThereChanges == true) {
            numberOfDays++;
        }
    }

    printf("%lld ", numberOfDays);

    return 0;
}
