#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> movies;

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        movies.push_back({end, start});
    }

    sort(movies.begin(), movies.end());


    int ans = 0;
    multiset<int> time;
    
    for (int i = 0; i < k; i++) {
        time.insert(0);
    }

    for (int i = 0; i < n; i++) {
        auto it = time.upper_bound(movies[i].second);

        if (it == time.begin()) continue;

        time.erase(--it);
        time.insert(movies[i].first);
        ans++;
    }

    cout << ans << "\n";

}