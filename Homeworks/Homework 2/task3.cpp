#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long N;
    string numbers = "", smallLetters = "", capitalLetters = ""; 
    char number;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> number;
        if (number >= 'a' && number <= 'z') {
            smallLetters += number;
        }
        else {
            if (number >= 'A' && number <= 'Z') {
                capitalLetters += number;
            }
            else {
                numbers += number;
            }
        }
    }
   
   sort(numbers.begin(), numbers.end());
   sort(smallLetters.begin(), smallLetters.end());
   sort(capitalLetters.begin(), capitalLetters.end()); 
   
   cout << numbers << smallLetters << capitalLetters << endl;
   
    return 0;
}
