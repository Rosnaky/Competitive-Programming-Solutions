#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> movies;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        movies.push_back({end, start});
    }

    sort(movies.begin(), movies.end());

    int ans = 0;
    int time = 0;

    for (pair<int, int>& movie : movies) {
        int start = movie.second;
        int end = movie.first;

        if (start < time) continue;

        time = end;
        ans++;
    }
    cout << ans;
}