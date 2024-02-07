#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int n, m, k;
bool check(vector<int> a, vector<int> &h) {
    vector<int> cowPos(n+1, -1);

    for (int i = 1; i <= n; i++) {
        if (a[i] != -1) {cowPos[a[i]] = i;}
    }

    int hi = 0;
    for (int i = 1; i <= n && hi < m; i++) {
        if (cowPos[h[hi]] != -1) {
            if (i > cowPos[h[hi]]) return false;

            i = cowPos[h[hi]];
            hi++;
        }
        else {
            while (i <= n && a[i] != -1) i++;
            if (i == n+1) return false;
            
            a[i] = h[hi];
            cowPos[h[hi]] = i;
            hi++;
        }
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("milkorder.in", "r", stdin); freopen("milkorder.out", "w", stdout);

     cin >> n >> m >> k;

    vector<int> a(n+1, -1);
    vector<int> h(m);
    for (int& i : h) cin >> i;
    for (int i = 0; i < k; i++) {
        int c, p; cin >> c >> p;
        a[p]=c;
    }

    for (int i = 1; i <= n;i++) {
        if (a[i] == -1) {
            a[i] = 1;
            if (check(a, h)) {
                cout << i;
                return 0;
            }
            a[i] = -1;
        }
    }
}