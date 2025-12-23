#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> par;
vector<int> rnk;

void makeSet(int n) {
    par[n] = n;
    rnk[n] = 1;
}

int Find(int n) {
    if (par[n] == n) return n;

    return par[n] = Find(par[n]);
}

bool Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a != b) {
        if (rnk[a] < rnk[b]) {
            swap(a, b);
        }

        par[b] = a;
        rnk[a] += rnk[b];
        return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);


    int n, m;
    cin >> n >> m;

    par = vector<int>(n+1);
    rnk = vector<int>(n+1);

    for (int i = 1; i <= n; i++) {
        makeSet(i);
    }

    vector<bool> open(n+1, 0);

    vector<vector<int>> adj(n+1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> barns(n);

    for (int &i : barns) cin >> i;

    vector<bool> ans(n);

    int components = 0;

    for (int i = n-1; i >= 0; i--) {
        components++;
        open[barns[i]] = 1;
        for (int p : adj[barns[i]]) {
            if (open[p]) {
                if (Union(barns[i], p)) {
                    components--;
                }
            }
        }

        if (components == 1) {
            ans[i] = 1;
        }
    }

    for (bool i : ans) {
        if (i) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
 

}