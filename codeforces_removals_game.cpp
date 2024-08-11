#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool equals(vector<int>& a , vector<int>& b) {
    unordered_map<int, int> freq;
    for (int i : a) freq[i]++;
    for (int i : b) freq[i]--;

    for (auto [k, v] : freq) {
        if (v != 0) return false;
    }

    return true;
}

void solve() {
    int n; cin >> n;

    vector<int> a(n), b(n);

    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;
    
    if (n <= 2 || equals(a, b)) {
        cout << "Bob\n";
        return;
    }

    cout << "Alice\n";

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}