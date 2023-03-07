#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numberOfCitizens, current;
   vector<int> citizens;

    cin >> numberOfCitizens;
    for (int i = 0; i < numberOfCitizens; i++) {
        cin >> current;


        auto position = lower_bound(citizens.begin(), citizens.end(), current);
        citizens.insert(position, current);

        int currentNumberOfCitizens = citizens.size();

        if (currentNumberOfCitizens % 2 == 1) {
            cout << fixed << setprecision(1) << (double)citizens[currentNumberOfCitizens/2] << '\n';
        }
        else {
            cout << fixed << setprecision(1) << (double)(citizens[currentNumberOfCitizens / 2] + citizens[currentNumberOfCitizens/2-1])/2. << '\n';
        }
    }

    return 0;
}
