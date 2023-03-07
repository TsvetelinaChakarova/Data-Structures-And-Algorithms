#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int numberOfWords;
    int maxLength = 0;
    vector<string> words;
    string currentWord;
    vector<char> result;

    cin >> numberOfWords;
    for (int i = 0; i < numberOfWords; i++) {
        cin >> currentWord;
        if (find(words.begin(), words.end(), currentWord) == words.end()) {
            words.push_back(currentWord);
            if (currentWord.size() > maxLength) {
                maxLength = currentWord.size();
            }
        }
    }

    for (int i = 0; i < numberOfWords; i++) {
        if (find(result.begin(), result.end(), words[i][0]) == result.end()) {
            result.push_back(words[i][0]);
        }
    }
    
    int i = 1;
    while (i <= maxLength) {
        for (int j = 0; j < numberOfWords; j++) {
            if (words[j].size() > i && find(result.begin(), result.end(), words[j][i]) == result.end()) {
                    if (j != 0 && words[j - 1].size() == words[j].size() && words[j - 1][i] != words[j][i]) {
                        auto iter = find(result.begin(), result.end(), words[j-1][i]);
                        result.insert(result.begin() + (iter - result.begin()) + 1, words[j][i]);
                    }
                    else {
                        if (j+1 != numberOfWords && (words[j + 1].size() == words[j].size() && words[j + 1][i] != words[j][i])) {
                            auto iter = find(result.begin(), result.end(), words[j+1][i]);
                            result.insert(result.begin() + (iter - result.begin()), words[j][i]);
                        }
        
                    }
                }
            }

        i++;
    }
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " "; 
    }

    return 0;
}
