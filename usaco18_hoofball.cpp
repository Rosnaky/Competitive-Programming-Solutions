#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <set>


using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);

    int n; cin >> n;

    vector<int> cows(n);
    
    for (int &i : cows) cin >> i;

    sort(cows.begin(), cows.end());

    vector<set<int>> reaches(n);
    
    for (int i = 0; i < n; i++) {
        reaches[i].insert(i);
        
        vector<bool> seen(n);
        int j = i;
        while (j >= 0 && j < n && !seen[j]) {
            seen[j] = 1;
            if (j > 0 && j+1 < n) j = cows[j]-cows[j-1] <= cows[j+1]-cows[j] ? j-1 : j+1;
            else if (j == 0 && j+1 < n) j = j+1;
            else if (j == n-1 && j-1 >= 0) j = j-1;

            reaches[i].insert(j);
        }
    }

    int total = 0, ans = 0;

    while (total < n && ans < n) {
        int maxi = 0, temp = 0;
        for (int i = 0; i < n; i++) {
            if (reaches[i].size() > temp) {
                maxi = i, temp = reaches[i].size();
            }
        }

        total += temp, ans++;

        while (reaches[maxi].size()) {
            int a = *reaches[maxi].begin();
            for (set<int>& s : reaches) {
                if (s.count(a)) s.erase(a);
            }
        }
    }

    cout << ans;

}