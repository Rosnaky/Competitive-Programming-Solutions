#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct node {
    node *lv = nullptr, *rv = nullptr;
    pair<int, int> key;
    int prior;
    int minl = 1e9;
};

static inline int minl(node *v) {
    return (v == nullptr ? 1e9 : v->minl);
}

void solve() {

    int n; cin >> n;
    set<int> a;

    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        a.insert(t);
    }

    int m; cin >> m;

    while (m--) {



    }

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();

}