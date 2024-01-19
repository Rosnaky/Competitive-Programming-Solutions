#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int h, c, t;
double func(long long k){
    double x = (double) ((k+1)*h + k*c)/(2*k+1);
    return abs(x-t);
}

void solve() {
     cin >> h >> c >> t;

    if (t <= (h+c)/2) {
        cout << 2 <<"\n";
        return;
    }

    int lo = 0, hi = 1e9;
    while (lo < hi) {
        int k = (lo+hi)/2;
        if (func(k) <= func(k+1)) {
            hi = k;
        }
        else {
            lo = k+1;
        }
    }
    cout << 2*lo+1 << "\n";
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t; while (t--) solve();
}