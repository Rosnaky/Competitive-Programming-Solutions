#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    int n; cin >> n;

    vector<pair<int, pair<int, int>>> q(n);
    map<int, int> cows;

    for (int i = 0; i < n; i++) {
        int day; string name, amount; cin >> day >> name >> amount;

        int temp = stoi(amount.substr(1, amount.size()-1));

        if (amount[0] == '-') temp*=-1;

        q[i] = {day, {name == "Mildred" ? 0 : name == "Eslie" ? 1 : 2, temp}};
        cows[name == "Mildred" ? 0 : name == "Eslie" ? 1 : 2] = 7;
    }

    sort(q.begin(), q.end());

    int ans = 0, highest = 7, count = 3; vector<bool> curr(n, 1); 
    bool prevDay = 0;
    for (int i = 0; i < n; i++) {
        int name = q[i].second.first; int change = q[i].second.second;
        cows[name] += change;

        if (curr[name] && count == 1 && cows[name] < highest) {
            highest = max(cows[0], max(cows[1], cows[2]));
            count = 0;
            for (int j = 0; j < 2; j++) {
                curr[i] = false;
                if (cows[j] == highest) {
                    count++;
                    curr[j] = true;
                }
            }
            if (count != 1 || !cows[name]) prevDay = true;
        }
        else if (curr[name] && cows[name] < highest) {
            count--;
            curr[name] = false;
            prevDay = true;
        }
        else if (cows[name] > highest) {
            highest = cows[name];
            count = 1;
            for (int j = 0; j < 2; j++) curr[j] = false;
            curr[name] = true;
            prevDay = true;
        }

        if (i == 0 || (i != 0 && q[i].first != q[i-1].first)) {
            ans += prevDay;
            prevDay = false;
        }
    }

    cout << ans;
}
