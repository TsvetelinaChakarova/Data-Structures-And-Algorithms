#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string word;
    unsigned long numberOfSymbols;
    char symbol;
    bool isSymbolInWord = false;
    unsigned int numberOfTheSymbolInTheWord = 0;
   
    cin>>word >> numberOfSymbols >> symbol;

    for (int i = 0; i < word.length(); i++) {
       if (word[i] == symbol) { 
           isSymbolInWord = true;
           numberOfTheSymbolInTheWord++;
        }
    }
   
    unsigned long count = numberOfSymbols / word.length() * numberOfTheSymbolInTheWord;
        for (int i = 0; i < numberOfSymbols % word.length(); i++) {
            if (word[i] == symbol) count++;
        }
    
    cout << count << endl;
      
    return 0;
}
