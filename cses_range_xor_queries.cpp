#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    vector<long long> nums(n+1);
    
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        nums[i] ^= nums[i-1];
    }

    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;

        cout << (nums[b]^nums[a-1]) << "\n";
    }
}