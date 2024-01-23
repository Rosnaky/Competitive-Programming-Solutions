#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll product = 1;
    vector<int> ans;
    int n; cin >> n;

    for (int i = 1; i < n; i++) {
        if (gcd(i, n) == 1) 
        {
            product *= i;
            product %= n;
            ans.push_back(i);
        }
    }

    if (product == 1) {
        cout << ans.size() << "\n";
        for (auto i : ans) cout << i << " ";
    }
    else {
        cout << ans.size()-1 << "\n";
        for (auto i : ans) if (i!=product) cout << i << " ";
    }

}