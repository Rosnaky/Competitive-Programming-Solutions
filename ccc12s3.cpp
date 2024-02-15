#include <vector>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<int> count(1001);

    int n; cin >> n;
    
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        count[x]++;
    }

    priority_queue<pair<int, int>> queue;
    for (int i = 0; i <= 1000; i++) {
        if (count[i] != 0) queue.push({count[i], i});
    }

    set<int> highest, lowest;

    int curr = queue.top().first;
    while (!queue.empty() && queue.top().first == curr) {
        highest.insert(queue.top().second);
        queue.pop();
    }
    
    if (!queue.empty()) {
        curr = queue.top().first;
        while (queue.top().first == curr) {
            lowest.insert(queue.top().second);
            queue.pop();
        }
    }

    
    int x, y;
    x = *highest.begin();
    y = *highest.rbegin();
    int ans = abs(x - y);
    
    if (lowest.size() != 0 && ans == 0) {
        y = *--lowest.end();
        ans = max(ans, abs(x-y));

        x = *--highest.end();
        ans = max(ans, abs(x-y));

        x = *highest.begin();
        y = *lowest.begin();
        ans = max(ans, abs(x-y));

        y = *--highest.end();
        x = *lowest.begin();
        ans = max(ans, abs(x-y));
    }
    

    cout << ans;
}