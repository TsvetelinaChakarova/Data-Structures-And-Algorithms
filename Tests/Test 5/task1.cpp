#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
using namespace std;


int main() {
    
    map<string, int> numbers;
    vector<string> words;
    int n;
    string current;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> current;
        words.push_back(current);
        numbers[current]++;
    }
    
    for (int i = 0; i < n; i++) {
        cout << numbers[words[i]] << " ";
    }
    
    
    
    return 0;
}
