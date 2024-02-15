#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;


int t, n; 

int solve(vector<int>& teams, set<pair<int, int>>& games) {
    if (games.size() == 0) {
        int winner = 0, curr = 0; bool repeat = false;

        for (int i = 1; i <= 4; i++) {
            if (teams[i] == curr) {
                repeat = true;
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
            return 1;
        }
        return 0;
    }

    int ans = 0;

    auto [a, b] = *games.begin();
    games.erase(games.begin());

    teams[a] += 3;
    ans += solve(teams, games);
    teams[a] -= 3;

    teams[b] += 3;
    ans += solve(teams, games);
    teams[b] -= 3;

    teams[a]++, teams[b]++;
    ans += solve(teams, games);
    teams[a]--, teams[b]--;

    games.insert({a, b});

    return ans;
} 


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t >> n;

    vector<int> teams(5);
    set<pair<int, int>> games;
    games.insert({1, 2});
    games.insert({1, 3});
    games.insert({1, 4});
    games.insert({2, 3});
    games.insert({2, 4});
    games.insert({3, 4});


    for (int i = 0; i < n; i++) {
        int a, b, s, t; cin >> a >> b >> s >> t;

        games.erase({a, b});

        if (s > t) teams[a] += 3;
        else if (s < t) teams[b] += 3;
        else { teams[a]++; teams[b]++; }
    }

    cout << solve(teams, games);
    
}