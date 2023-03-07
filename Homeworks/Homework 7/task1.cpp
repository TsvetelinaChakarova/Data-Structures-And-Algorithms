#include <iostream>
#include <set>
#include <iterator>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    int current;
    set<int> result;
    result.insert(0);
 
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> current;
        for (int j = current; j > 0 ; j = (j - 1) & current) {
            result.insert(j);
        }
    }

    cout << result.size() << endl;
    
    return 0;
}
