#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


bool cmp1(const pair<int, vector<int>>& p1, const pair<int, vector<int>>& p2) {return p1.first < p2.first;}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    int n; cin >> n;
    int end = 0;

    vector<pair<int, vector<int>>> cows(n);
    for (int i = 0; i < n; i++) {
        int s, t, b; cin >> s >> t >> b;
        cows[i] = {s, {t, b}};
        end = max(end, t);
    }

    // sort(cows.begin(), cows.end(), cmp1);

    int ans = 0;
    for (int time = 1; time <= end; time++) {
        int curr = 0;
        for (auto& c : cows) {
            if (c.first <= time && c.second[0] >= time) curr += c.second[1];
        }
        ans = max(ans, curr);
    }
    cout << ans;
    
}