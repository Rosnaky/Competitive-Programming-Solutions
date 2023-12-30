#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

vector<ll> positions;
vector<ll> hearing;
vector<ll> rate;
int n;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    positions = vector<ll>(n);
    hearing = vector<ll>(n);
    rate = vector<ll>(n);

    int left=1e9, right=0;
    for (int i = 0; i < n; i++) {
        int p, h, r;
        cin >> p >> r >> h;
        positions[i] = p, hearing[i] = h, rate[i] = r;
        left = min(left, p);
        right = max(right, p);
    }

    ll ans = 1e15;
    for (int i = left; i <= right; i++) {
        ll temp = 0;

        for (int j = 0; j < n; j++) {
            temp += max(ll(0), abs(i-positions[j])-hearing[j])*rate[j];
        }
        ans = min(ans, temp);
    }
    
    cout << ans;
}