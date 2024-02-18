#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;


int n, t;

bool valid(int k, vector<int>& arr) {
    int time = 0;
    priority_queue<int> stage;
    for (int i = 0; i < n; i++) {
        if (stage.size() == k) {
            time = -stage.top();
            stage.pop();
        }
        if (time + arr[i] > t) return false;
        else {
            stage.push(-time-arr[i]);
        }
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);

     cin >> n >> t;

    vector<int> arr(n);
    for (int &i : arr) cin >> i;

    int l = 1, r = n;
    int mid;
    while (l != r) {
        mid = (l+r)/2;
        if (valid(mid, arr)) {
            r = mid;
        }
        else l = mid+1;
    }

    cout << l;
}