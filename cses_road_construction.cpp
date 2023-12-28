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

    int n, m;
    cin >> n >> m;

    par = vector<int>(n+1);
    rnk = vector<int>(n+1);
    vector<pair<int, int>> edges;

    for (int i = 1; i <= n; i++) makeSet(i);

    int components = n, maxSize = 1;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        if (Union(a, b)) {
            components--;
            maxSize = max(maxSize, max(rnk[Find(a)], rnk[Find(b)]));
        }
        cout << components << " " << maxSize << "\n";
    }


}