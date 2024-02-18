#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int prefix[5008][5008];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector<int> heights(n+1);
    for (int i = 1; i <= n; i++) cin >> heights[i];


    for (int i = 1; i <= n; i++) {
        int left = 1, right = i;
        int best = 1e9;
        while (right <= n) {
            prefix[left][right] = abs(heights[left] - heights[right]) + prefix[left+1][right-1];
            best = min(prefix[left][right], best);
            left++;
            right++;
        }

        cout << best << " ";
    }
}