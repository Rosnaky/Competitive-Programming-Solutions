#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int a1, a2, b1, b2; int k;

int dfs(int c, int p, map<int, int>& seen) {
    if (k == c) return p;
    if (seen.count(p)) {
        k %= seen[p];
        seen.clear();
        c = 0;
    }

    if (p >= a1 && p <= a2) {
        p = a2 - p + a1;
    }
    if (p >= b1 && p <= b2) {
        p = b2 - p + b1;
    }
    if (!(p >= b1 && p <= b2) && !(p >= a1 && p <= a2)) {
        return p;
    }
    return seen[c] = dfs(c+1, p, seen);
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("swap.in", "r", stdin); freopen("swap.out", "w", stdout);

    int n; cin >> n >> k;
    cin >> a1 >> a2 >> b1 >> b2;
    a1--, a2--, b1--, b2--;

    vector<int> nums(n);
    map<int, int> seen;
    for (int i = 1; i <= n; i++) {
        nums[dfs(0, i-1, seen)] = i;
        seen.clear();
    }

    for (int i : nums) cout << i << "\n";
}