#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numberOfFighters;
    long long int currentFighter;
    deque<long long int> positiveFighters;

    cin >> numberOfFighters;
    for (int i = 0; i < numberOfFighters; i++) {
        cin >> currentFighter;

        if (currentFighter > 0) {
            positiveFighters.push_front(currentFighter);
        }
        else {

            if (positiveFighters.size() == 0) {
                printf("%lld ", currentFighter);
            }
            else {
                bool isNegativeFighterGone = false;

                while (positiveFighters.size() != 0 && isNegativeFighterGone != true) {

                    if (abs(currentFighter) < positiveFighters.front()) {
                        isNegativeFighterGone = true;
                    }

                    if (abs(currentFighter) == positiveFighters.front()) {
                        isNegativeFighterGone = true;
                        positiveFighters.pop_front();
                    }

                    else
                        if (abs(currentFighter) > positiveFighters.front()) {
                            positiveFighters.pop_front();
                        }
                }

                if (positiveFighters.size() == 0 && isNegativeFighterGone == false) {
                    printf("%lld ", currentFighter);
                }
            }
        }
    }

    while (!positiveFighters.empty()) {
        printf("%lld ", positiveFighters.back());
        positiveFighters.pop_back();
    }
  
    return 0;
}
