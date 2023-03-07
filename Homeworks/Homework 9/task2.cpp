#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numberOfAnimals;
    int K;
    int currentAnimal;
    vector<int> animals;
    unordered_map<int, int> animalsMapXs, animalsMapZs;

    long long int result = 0;

    cin >> numberOfAnimals;
    cin >> K;
    for (int i = 0; i < numberOfAnimals; i++) {
        cin >> currentAnimal;
        animals.push_back(currentAnimal);
        if (animalsMapXs.count(animals[i]) == 0) {
            animalsMapXs.insert({ animals[i], 1 });
        }
        else {
            animalsMapXs[animals[i]]++;
        }
    }

    for (int i = 0; i < numberOfAnimals; i++) {
        if (animalsMapXs[animals[i]] > 0) {
            animalsMapXs[animals[i]]--;
        }

        result += animalsMapZs[animals[i] / K] * animalsMapXs[animals[i] * K];
        
        if (animalsMapZs.count(animals[i]) == 0) {
            animalsMapZs.insert({ animals[i], 1 });
        }
        else {
            animalsMapZs[animals[i]]++;
        }
    }

    printf("%lld", result);
    return 0;
}
