#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> par;
vector<int> rnk;
vector<int> relevance;

void makeSet(int n) {
    par[n] = n;
    rnk[n] = 1;
}

int Find(int n) {
    if (par[n] == n) return n;

    return par[n] = Find(par[n]);
}

int Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a != b) {
        par[b] = a;
        rnk[a] += rnk[b];
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    int n, q; cin >> n >> q;

    par = vector<int>(n+1);
    rnk = vector<int>(n+1);

    for (int i = 1; i <= n; i++) {
        makeSet(i);
    }

    vector<vector<int>> edges(n-1);

    for (int i = 0; i < n-1; i++) {
        int p, q, r; cin >> p >> q >> r;

        edges[i] = {p, q, r};
    }

    vector<vector<int>> queries(q);

    for (int i = 0; i < q; i++) {
        int k, v; cin >> k >> v;
        queries[i] = {i, k, v};
    }


    sort(queries.begin(), queries.end(), [](const vector<int>& a, const vector<int>& b) {return a[1] > b[1];});
    sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {return a[2] > b[2];});

    vector<int> ans(q);

    int curr = 0;
    for (int i = 0; i < q; i++) {
        int j = queries[i][0], k = queries[i][1], v = queries[i][2];

        while (curr < n-1 && edges[curr][2] >= k) {
            Union(edges[curr][1], edges[curr][0]);
            curr++;
        }

        ans[j] = rnk[Find(v)]-1;
    }

    for (int i : ans) {
        cout << i << '\n';
    }

}