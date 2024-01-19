#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;

    vector<int> nums(n);
    for (int& i : nums) cin >> i;

    int ans = 0;

    for (int a = 0; a < n; a++) {
        for (int l = a+1; l < n; l++) {
            ll num = nums[a]*nums[l];

            if (num == 1) {
                ans++;
                continue;
            }

            for (int i = sqrt(num); i >= 2; i--) {
                if (num%i == 0) {
                    ll temp = 1;
                    for (int j = 0; j < k; j++) {
                        temp*=i;
                    }
                    if (temp == num) {
                        ans++;
                    }
                    else if (temp < num) break;
                }
            }
        }
    }


    cout << ans;
}