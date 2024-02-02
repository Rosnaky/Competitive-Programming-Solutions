#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("traffic.in", "r", stdin); freopen("traffic.out", "w", stdout);

    int n; cin >> n;
    vector<vector<int>> queries(n);
    for (int i = 0; i < n; i++) {
        string t; int a, b; 
        cin >> t >> a >> b;
        queries[i] = {(t=="none" ? 0 : (t=="on" ? 1 : 2)), a, b};
    }

    int upper = 1e9, lower = 0;

    for (int i = n-1; i >= 0; i--) {
        if (queries[i][0] == 1) {
            upper -= queries[i][1];
            lower -= queries[i][2];
            lower = max(0, lower);
        }
        else if (queries[i][0] == 2) {
            upper += queries[i][2];
            lower += queries[i][1];
        }
        else {
            lower = max(lower, queries[i][1]);
            upper = min(upper, queries[i][2]);
        }
    }
    
    cout << lower << " " << upper << "\n";

    
    for (int i = 0; i < n; i++) {
        if (queries[i][0] == 0) {
            lower = max(lower, queries[i][1]);
            upper = min(upper, queries[i][2]);
        }
        else if (queries[i][0] == 1) {
            lower += queries[i][1];
            upper += queries[i][2];
        }
        else {
            lower -= queries[i][2];
            upper -= queries[i][1];
            lower = max(lower, 0);
        }
    }
    
    cout << lower << " " << upper << "\n";
}