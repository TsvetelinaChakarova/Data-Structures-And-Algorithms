#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void merge(vector<pair<long long, int>>& array, int left, int middle, int right) {

    long long leftArraySize = middle - left + 1;
    long long rightArraySize = right - middle;
    vector<pair<long long, int>> leftArr(leftArraySize), rightArr(rightArraySize);

    for (int i = 0; i < leftArraySize; i++) {
        leftArr[i].first = array[left + i].first;
        leftArr[i].second = array[left + i].second;
    }

    for (int j = 0; j < rightArraySize; j++) {
        rightArr[j].first = array[middle + 1 + j].first;
        rightArr[j].second = array[middle + 1 + j].second;
    }

    int i = 0, j = 0, k = left;

    while (i < leftArraySize && j < rightArraySize) {
        if (leftArr[i].first <= rightArr[j].first) {
            array[k].first = leftArr[i].first;
            array[k].second = leftArr[i].second;
            i++;
        }

        else {
            array[k].first = rightArr[j].first;
            array[k].second = rightArr[j].second;
            j++;
        }

        k++;
    }

    while (i < leftArraySize) {
        array[k].first = leftArr[i].first;
        array[k].second = leftArr[i].second;
        i++; k++;
    }

    while (j < rightArraySize) {
        array[k].first = rightArr[j].first;
        array[k].second = rightArr[j].second;
        j++; k++;
    }
}

void mergeSort(vector <pair<long long, int>>& array, int left, int right) {
    int middle;
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
}

int main() {

    int numberOfLoggs;
    string date; 
                 
    vector<pair<long long, int>> loggsAndIndexes;

    cin >> numberOfLoggs;
    cin.ignore();
    
    for (int i = 0; i < numberOfLoggs; i++) {
        getline(cin, date);
        loggsAndIndexes.push_back(make_pair(
            (date[0] - '0') * pow(10, 5) + (date[1] - '0') * pow(10, 4) + (date[3] - '0') * pow(10, 3)
            + (date[4] - '0') * pow(10, 2)
            + (date[6] - '0') * pow(10, 1) + (date[7] - '0') * pow(10, 0)
            + (date[9] - '0') * pow(10, 7) + (date[10] - '0') * pow(10, 6)
            + (date[12] - '0') * pow(10, 9) + (date[13] - '0') * pow(10, 8)
            + (date[15] - '0') * pow(10, 13) + (date[16] - '0') * pow(10, 12)
            + (date[17] - '0') * pow(10, 11) + (date[18] - '0') * pow(10, 10), i + 1));

    }

    mergeSort(loggsAndIndexes, 0, loggsAndIndexes.size() - 1);
   
    for (int i = 0; i < loggsAndIndexes.size(); i++) {
        cout << loggsAndIndexes[i].second << endl;
    }
    
    return 0;
}
