#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numberOfEmployees, currentParent, currentChild;
    cin >> numberOfEmployees;
    vector<pair<int, int>> pairs;
    vector<int> result(numberOfEmployees);


    for (int i = 0; i < numberOfEmployees - 1; i++) {
        cin >> currentParent;
        cin >> currentChild;
        pairs.push_back(make_pair(currentParent, currentChild));
    }

    for (int i = numberOfEmployees - 1; i >= 0; i--) {
        bool isThereOnce = false;
        bool isThereAtLeastTwice = false;
        int firstOccurence = -1, lastOccurance = -1;

        for (int j = 0; j < numberOfEmployees - 1; j++) {
            if (pairs[j].first == i && isThereOnce == false) {
                isThereOnce = true;
                firstOccurence = j;
            }
            else {
                if (pairs[j].first == i && isThereOnce == true) {
                    isThereAtLeastTwice = true;
                    lastOccurance = j;
                }
                else {
                    if (pairs[j].first != i && isThereOnce == true) {
                        break;
                    }
                }
            }

        if (firstOccurence == -1 && lastOccurance == -1) {
            result[i] = 0;
        }
        else {
            if (firstOccurence != -1 && lastOccurance == -1) {
                result[i] = 1 + result[pairs[firstOccurence].second];
            }
            else {
                    result[i] = lastOccurance - firstOccurence + 1;
                    for (int k = firstOccurence; k <= lastOccurance; k++) {
                        result[i] += result[pairs[k].second];
                    }
                }
            }
        }
    }

        for (int i = 0; i < result.size(); i++) {
            printf("%d ", result[i]);
        }

        return 0;
    }
