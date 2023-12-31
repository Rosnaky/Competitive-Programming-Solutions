#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> a = {1, 2, 3, 4, 5 ,6, 7, 8};
    int s = 100;
    int n = a.size();

    for (int mask = 0; mask < (1 << n); mask++) {
        int curr = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                curr += a[i];
            }
        }
        if (curr == s) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}