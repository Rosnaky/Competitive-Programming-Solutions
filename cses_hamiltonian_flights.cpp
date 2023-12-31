#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

#define mod int(1e9+7)

vector<int> adj[21];
ll dp[1<<20][21];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }

    dp[1][1] = 1;

    for(int s = 2; s < (1<<n); s++) { // we start from the second city
		if((s & (1 << (n-1))) && s != ((1<<n) - 1)) continue;
		for(int d = 1; d <= n; d++) { // loop through each city
			if((s & (1 << (d-1))) == 0) continue;
			for(int v : adj[d]) {
				if(s & (1<<(v-1))) { // if v is in the mask
					dp[s][d] += dp[s-(1<<(d-1))][v];
					dp[s][d] %= mod;
				}
			}
		}
	}

    cout << dp[(1<<n)-1][n]%mod;
}