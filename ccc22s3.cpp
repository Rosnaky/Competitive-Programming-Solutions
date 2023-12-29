#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n, m, k;
vector<vector<int>> ans;

ll paths(int a) {
    ll s = 0;
    for (int i = 1; i <= a; i++) {
        s += i;
    }
    return s;
}

ll getGood(vector<ll>& curr) {
    ll good = 0;
    vector<ll> count(m+1);
    ll left = 0, right = 1;
    while (right < curr.size()) {
        count[curr[right]]++;

        if (count[curr[right]] > 1 || right == curr.size()-1) {
            good+=paths(right-left+1);
            left = right+1;
            right = left;
            count = vector<ll>(m+1);
        }
        
        right++;

        // cout << left << " " << right << endl;
        
        // while ((count[curr[left]] > 1 || count[curr[right]] > 1)) {
        //     count[curr[left]]--;
        //     left++;
        // }

    }

    return good;
}

void backtrack(vector<ll>& curr) {
    if (curr.size() == n && getGood(curr) == k) {
        for (int c : curr) {
            cout << c << " ";
        }
        exit(0);
    }
    // if (getGood(curr) > k) return;

    for (int i = 1; i <= m; i++) {
        curr.push_back(i);
        backtrack(curr);
        curr.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m >> k;

    vector<ll> curr;
    backtrack(curr);
    cout << -1;
}