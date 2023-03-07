#include <iostream>
#include <set>
#include <iterator>
#include <vector>
#include <bitset>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numberOfRequests;
    long long int currentRequest;
    long long int results;
    set<long long int> requests;
    requests.insert(0);

    cin >> numberOfRequests;

    cin >> currentRequest;
    requests.insert(currentRequest);
    results = currentRequest;
    printf("%lld\n", results);

    for (int i = 1; i < numberOfRequests; i++) {
        cin >> currentRequest;
        requests.insert(currentRequest);

        auto current = requests.lower_bound(currentRequest);
       
        if (*current != *requests.rbegin()) {
            current++;
            long long int currentXor1 = *current ^ currentRequest;
            current--;
            current--;
            long long int currentXor2 = *current ^ currentRequest;
            long long int minimumXor;
            if (currentXor1 < currentXor2) {
                minimumXor = currentXor1;
            }
            else {
                minimumXor = currentXor2;
            }

            if (results < minimumXor) {
                printf("%lld\n", results);
            }
            else {
                printf("%lld\n", minimumXor);
                results = minimumXor;
            }
        }

        else {
            current--;
            if (results < (*current ^ currentRequest)) {
                printf("%lld\n", results);
            }
            else {
                printf("%lld\n", *current ^ currentRequest);
                results = *current ^ currentRequest;
            }
        }

    }
    
    return 0;
}
