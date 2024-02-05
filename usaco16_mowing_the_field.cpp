#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("mowing.in", "r", stdin); freopen("mowing.out", "w", stdout);

    int n; cin >> n;

    map<pair<int, int>, int> visited;
    visited[{0,0}] = 0;
    int time = 0;
    pair<int, int> curr = {0, 0};

    int ans = 1e9;

    while (n--) {

        char c; int steps; cin >> c >> steps;
        pair<int, int> dir;
        if (c == 'N') dir = {1, 0};
        else if (c == 'E') dir = {0, 1};
        else if (c == 'W') dir = {0, -1};
        else dir = {-1, 0};

        for (int i = 1; i <= steps; i++) {
            curr = {curr.first + dir.first, curr.second+dir.second};

            if ((visited.count(curr))) {
                ans = min(ans, time+i-visited[curr]);
            }
            visited[curr] = time+i;
        }

        time += steps;

    }

    cout << (ans == 1e9 ? -1 : ans);

}