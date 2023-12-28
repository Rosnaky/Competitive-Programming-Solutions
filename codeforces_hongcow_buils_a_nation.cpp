#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

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
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    par = vector<int>(n+1);
    rnk = vector<int>(n+1);
    vector<pair<int, int>> edges;

    for (int i = 1; i <= n; i++) makeSet(i);
    set<int> gov;
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        gov.insert(a);
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }
    

    int maxSize = 0; bool g = false;
    for (pair<int, int>& e : edges) {
        if (g && (gov.count(e.first) || gov.count(e.second))) continue;
        if (gov.count(e.first) && gov.count(e.second)) continue;

        if (Union(e.first, e.second)) {
            maxSize = max(maxSize, rnk[Find(e.first)]);
        }
    }
    cout << maxSize;
}