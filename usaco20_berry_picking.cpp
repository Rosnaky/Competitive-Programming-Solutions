#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


vector<int> berries;
int n, k;

int solve(int x) {
    priority_queue<int> pq;
    for (int b : berries) pq.push(b);

    for (int i = 0; i*2 < k; i++) {
        if (pq.top() < x) return 0;
        int newVal = pq.top()-x;
        pq.pop();
        pq.push(newVal);
    }
    int ans = 0;
    for (int i = 0; i*2 < k && !pq.empty(); i++) {
        ans += min(pq.top(), x);
        int newVal = pq.top()-x;
        pq.pop();
        if (newVal > 0) pq.push(newVal);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);

    cin >> n >> k;

    berries = vector<int>(n);
    for (int& x : berries) {
        cin >> x;
    }

    int ans = 0;
    for (int x = 0; x <= 1000; x++) {
        ans = max(ans, solve(x));
    }
    cout << ans;
}