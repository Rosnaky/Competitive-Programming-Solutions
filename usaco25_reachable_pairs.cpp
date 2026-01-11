#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> par;
vector<int> rnk;


int Find(int n) {
    if (par[n] == n) return n;
    return par[n] = Find(par[n]);
}

bool Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a == b) return 0;

    par[b] = a;
    rnk[a] += rnk[b];
    return 1;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    string s; cin >> s;

    par = vector<int>(n);
    rnk = vector<int>(n);

    for (int i = 0; i < n; i++) {
        par[i] = i;
        rnk[i] = 1;
    }

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            rnk[Find(i)] = 0;
            for (int j: adj[i]) {
                if (s[j] == '1') {
                    Union(i, j);
                }
            }
        }
    }

    long long total_pairs = 0;
    vector<long long> ans(n);

    for (int i = n-1; i>= 0; i--) {

        if (s[i] == '1') {
            total_pairs += rnk[Find(i)];
            rnk[Find(i)]++;
        }
        else {
            for (int j : adj[i]) {
                if (j < i && s[j] == '0') continue;
                if (Find(i) == Find(j)) continue;
                
                total_pairs += (long long)rnk[Find(i)] * rnk[Find(j)];
                Union(i, j);
            }
        }

        ans[i] = total_pairs;
    }

    for (long long &i : ans) {
        cout << i << '\n';
    }


}