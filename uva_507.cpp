#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
#define BIG int(1e9+7)


// vector<int> route, memo;
int tc, t;
void solve() {
    int n;
    cin >> n;
    // route.assign(n-1, 0);
    // memo.assign(n-1, -BIG);
    
    int ans = 0;
    int curr = 0;
    int left = 1;
    int st = 1, ed = 1;

    for (int i = 2; i <= n; i++) {
        int temp; cin >> temp;
        curr += temp;
        if (curr < 0) curr = 0, left = i;
        if (curr >= ans) {
            
            if (curr > ans || (i - left > ed-st)) {
                st = left;
                ed = i;
            }
            
            
            ans = curr;
        }
    }

    if (ans == 0) cout << "Route " << tc-t << " has no nice parts\n";
    else cout << "The nicest part of route " << tc-t << " is between stops " << st << " and " << ed << "\n";
    
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    tc = t;
    while (t--) solve();
}