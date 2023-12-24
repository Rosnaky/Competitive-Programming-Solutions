#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

set<int> ans;

void backtrack(vector<int>& curr, vector<vector<int>>& buckets, int vol) {
    if (curr.size() == 4) {
        ans.insert(vol);
        return;
    }

    int barn = curr.size() % 2 == 0 ? 0 : 1;

    for (int i = 0; i < int(buckets[barn].size()); i++) {
        int temp = buckets[barn][i];
        if (temp == -1) continue;

        int newVol = barn == 0 ? vol - temp : vol + temp;
        curr.push_back(buckets[barn][i]);
        buckets[(barn+1)%2].push_back(temp);
        buckets[barn][i] = -1;

        backtrack(curr, buckets, newVol);
        curr.pop_back();
        buckets[(barn+1)%2].pop_back();
        buckets[barn][i] = temp;

        while (i < (int)buckets[barn].size() && buckets[barn][i] == temp) {
            i++;
        }
        i--;
    }
}


int main() {
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);

    vector<vector<int>> buckets(2, vector<int>(10));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 10; j++) {
            int temp;
            cin >> temp;
            buckets[i][j] = temp;
        }
    }

    vector<int> curr;
    backtrack(curr, buckets, 1000);

    cout << ans.size();
}