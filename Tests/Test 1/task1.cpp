#include <cmath>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    set<int> numbers;
    int current;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> current;
        numbers.insert(current);
    }
    
   for (auto i = numbers.begin(); i != numbers.end(); i++) {
       cout << *i << " ";
   }
    
    
    return 0;
}
