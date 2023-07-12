#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end()); // Sort the array in ascending order

        int maxCost = a[n - 1] - a[0]; // Calculate the initial maximum cost

        // Iterate through all possible split points and calculate the cost
        for (int i = 1; i < n; i++) {
            int cost = a[i] - a[i - 1];
            maxCost = max(maxCost, cost);
        }

        cout << maxCost << endl;
    }

    return 0;
}
