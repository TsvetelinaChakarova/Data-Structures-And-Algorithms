#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int current;
    unordered_map<int, int> numbersMap;
    vector<int> numbersVec;

    for (int i = 0; i < n; i++) {
        cin >> current;
        numbersVec.push_back(current);
        numbersMap[numbersVec[i]]++;  
    }
    
    int sum = 0;
    for (int i = 0; i <n; i++) {
       if(numbersMap[numbersVec[i]] % 2 == 1) {
           sum += numbersVec[i];
       }
    }
    
    cout << sum << endl;

    return 0;
}
