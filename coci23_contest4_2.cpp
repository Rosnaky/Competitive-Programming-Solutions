#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int n, t, a, b; 
vector<vector<ll>> memo;
ll dp(int node, int time, vector<ll>& arr) {
    if (node >= n) return 0;
    if (memo[node][time] != -1) return memo[node][time];
    
    
    ll ans = 0;
    if (time + a <= t) {
        ans = dp(node+1, time+a, arr) + arr[node];
    }
    if (time + b <= t) {
        ans = max(ans, dp(node+1, time+b, arr));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> t >> a >> b;
    memo = vector<vector<ll>>(n+1, vector<ll>(t+1, -1));
    
    vector<ll> arr(n);
    for (ll &i : arr) cin >> i;

    ll ans = dp(0, 0, arr);
    
    cout << ans;
}