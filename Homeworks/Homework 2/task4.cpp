#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Person
{
    double di, ti;
    unsigned int index;

};

void merge(vector<Person>& array, int left, int middle, int right) {

    int leftArraySize = middle - left + 1;
    int rightArraySize = right - middle;
    vector<Person> leftArr(leftArraySize), rightArr(rightArraySize);

    for (int i = 0; i < leftArraySize; i++) {
        leftArr[i] = array[left + i];
    }

    for (int j = 0; j < rightArraySize; j++) {
        rightArr[j] = array[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < leftArraySize && j < rightArraySize) {
        if (leftArr[i].di * leftArr[i].di / leftArr[i].ti > rightArr[j].di * rightArr[j].di / rightArr[j].ti) {
            array[k] = leftArr[i];
            i++;
        }

        else {
            if (leftArr[i].di * leftArr[i].di / leftArr[i].ti < rightArr[j].di * rightArr[j].di / rightArr[j].ti) {
                array[k] = rightArr[j];
                j++;
            }
            else {
                if (leftArr[i].di > rightArr[j].di)
                {
                    array[k] = leftArr[i];
                    i++;
                }
                else {
                    array[k] = rightArr[j];
                    j++;
                }
            }
        }

        k++;
    }

    while (i < leftArraySize) {
        array[k] = leftArr[i];
        i++; k++;
    }

    while (j < rightArraySize) {
        array[k] = rightArr[j];
        j++; k++;
    }
}

void mergeSort(vector<Person>& array, int left, int right) {
    int middle;
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
}

int main() {
    unsigned int N;
    double di, ti;
    vector<Person> people;

    cin >> N;
    for (unsigned int i = 1; i <= N; i++) {
        cin >> di >> ti;
        people.push_back({ di, ti, i });
    }

    mergeSort(people, 0, people.size() - 1);

    for (int i = 0; i < N; i++) {
        cout << people[i].index << " ";
    }
    return 0;
}
