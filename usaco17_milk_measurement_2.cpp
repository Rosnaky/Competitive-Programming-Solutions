#include <vector>
#include <iostream>
#include <algorithm>
#include <string>


using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);


    int n; cin >> n;

    vector<vector<int>> day(101);
    for (int i = 0; i < n; i++) {
        int a; string b, c; cin >> a >> b >> c;

        day[a] = {(b == "Mildred" ? 0 : (b == "Bessie" ? 1 : 2)), stoi(c)};
    }

    // sort(day.begin(), day.end());

    vector<int> cow(3, 7);
    int ans = 0;
    int curr = (1 << 3)-1;

    for (int i = 0; i < 101; i++) {
        if (!day[i].size()) continue;

        cow[day[i][0]] += day[i][1];

        int high = 0;
        for (int j = 0; j < 3; j++) high = cow[j] > cow[high] ? j : high;

        high = cow[high];
        int temp = 0;
        for (int j = 0; j < 3; j++) {
            temp |= (cow[j] == high) << j;
        }

        if (curr != temp) {
            ans++;
            curr = temp;
        }
    }

    cout << ans;
}