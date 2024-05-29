#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector<int> a(n), b(n);

    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    vector<ll> coeffs;
    ll sum = 0;

    for (ll i = 0; i < n; i++) {
        coeffs.push_back((i+1)*(n-i)*a[i]);
        // cout << coeffs[coeffs.size()-1] << " ";
    }
    sort(coeffs.begin(), coeffs.end());
    sort(b.begin(), b.end(), greater<int>());

    for (ll i = 0; i < n; i++) {
        sum += b[i]*coeffs[i];
    }

    cout << sum;
}