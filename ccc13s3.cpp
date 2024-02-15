#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int t, n;
set<vector<int>> ans;

void solve(vector<int> teams, set<pair<int, int>> gamesPlayed) {

    if (gamesPlayed.size() == 12) {

        int winner = 0, curr = 0; bool repeat = false;

        for (int i = 1; i <= 4; i++) {
            if (teams[i] == curr) {
                repeat == true;
                winner = i;
            }
            else if (teams[i] > curr) {
                repeat = false;
                winner = i;
                curr = teams[i];
            }
        }
        // for (int a : teams) cout << a << " "; cout << '\n';
        if (!repeat && winner == t) {
            ans.insert(teams);
        }
        return;
    }


    for (int a = 1; a <= 4; a++) {
        for (int b = 1; b <= 4; b++) {
            if (a == b || gamesPlayed.find({a, b}) != gamesPlayed.end()) continue;
            gamesPlayed.insert({a, b});
            gamesPlayed.insert({b, a});

            // Team a wins
            teams[a] += 3;
            solve(teams, gamesPlayed);
            teams[a] -= 3;

            // Team b wins
            teams[b] += 3;
            solve(teams, gamesPlayed);
            teams[b] -= 3;

            // Tie
            teams[a]++; teams[b]++;
            solve(teams, gamesPlayed);
            teams[a]--; teams[b]--;

            gamesPlayed.erase({a, b});
            gamesPlayed.erase({b, a});
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t >> n;

    set<pair<int, int>> gamesPlayed;

    vector<int> teams(5);
    for (int i = 0; i < n; i++) {
        int a, b, s, t;
        cin >> a >> b >> s >> t;

        gamesPlayed.insert({a, b});
        gamesPlayed.insert({b, a});

        if (s > t) {
            teams[a] += 3;
        }
        else if (s < t) {
            teams[b] += 3;
        }
        else {
            teams[a]++;
            teams[b]++;
        }
    }

    solve(teams, gamesPlayed);

    cout << ans.size();

}