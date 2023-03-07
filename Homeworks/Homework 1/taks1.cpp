#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int NO_SYMBOLS = -1;

int main() {
    int positionFromLeft = NO_SYMBOLS;
    int positionFromRight = NO_SYMBOLS;
    string testVariants;
    char symbol;

    cin >> testVariants;
    cin >> symbol;

    for (int i = 0; i < testVariants.length(); i++) {
        if (testVariants[i] == symbol) {
            cout << 0 << " ";
        }

        else {
            for (int j = i-1; j >= 0; j--) {
                if (testVariants[j] == symbol) {
                 positionFromLeft = i - j;
                 break;
                }
            }

            for (int j = i+1; j < testVariants.length(); j++) {
                if (testVariants[j] == symbol) {
                    positionFromRight = j - i;
                    break;
                }
            }

            if (positionFromRight == NO_SYMBOLS) {
                cout << positionFromLeft << " ";
            }
            else {
                if (positionFromLeft == NO_SYMBOLS) {
                    cout<< positionFromRight << " ";
                }
                else {
                    if (positionFromRight < positionFromLeft) {
                        cout<<positionFromRight<<" ";
                    }
                    else {
                        cout<< positionFromLeft << " ";
                    }
                }
            }
        }

        positionFromLeft = NO_SYMBOLS;
        positionFromRight = NO_SYMBOLS;
    }

    return 0;
}
