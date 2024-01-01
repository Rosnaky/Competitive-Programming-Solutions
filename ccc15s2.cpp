#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int j; cin >> j;
    int n; cin >> n;

    vector<char> sizes(j+1);

    for (int i = 1; i <= j; i++) {
        cin >> sizes[i];
    }
    vector<bool> seen(j+1);

    vector<pair<char, int>> requests(n);
    for (int i = 0; i < n; i++) {
        char c;
        int num; cin >> c >> num;

        requests[i] = {c, num};
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (requests[i].first == 'L' && !seen[requests[i].second] && sizes[requests[i].second] == 'L') {
            seen[requests[i].second] = true;
            ans++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (requests[i].first == 'M' && !seen[requests[i].second] && (sizes[requests[i].second] == 'L' || sizes[requests[i].second] == 'M')) {
            seen[requests[i].second] = true;
            ans++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (requests[i].first == 'S' && !seen[requests[i].second] && (sizes[requests[i].second] == 'S' || sizes[requests[i].second] == 'L' || sizes[requests[i].second] == 'M')) {
            seen[requests[i].second] = true;
            ans++;
        }
    }

    cout << ans;

}