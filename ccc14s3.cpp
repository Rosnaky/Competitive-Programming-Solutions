#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;


void solve() {

    int n; cin >> n;

    stack<int> mountain, branch;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        mountain.push(a);
    }

    int ans = 0;
    while (ans != n) {
        
        if (!mountain.empty() && mountain.top() == ans + 1) {
            mountain.pop();
            ans++;
        }
        else if (!branch.empty() && branch.top() == ans+1) {
            branch.pop();
            ans++;
        }
        else if (mountain.empty()) {
            cout << "N" << "\n";
            return;
        }
        else {
            branch.push(mountain.top());
            mountain.pop();
        }
    }

    cout << "Y" << "\n";
}


int main() {

    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}