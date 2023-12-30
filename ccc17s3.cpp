#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

vector<int> lengths;
vector<vector<int>> memo;
set<int> heights;
int n;

int length = 1;
int nums = 0;

int search(int board, vector<bool> seen, int h) {
    if (board > length) {
        length = board;
        nums = 1;
        heights.clear();
        heights.insert(h);
    }
    else if (board == length && heights.find(h) == heights.end()) {
        nums++;
        heights.insert(h);
    }
    else if (board == length) {
        return;
    }

    // if (board > n/2) return;
    // cout << board;
    // for (int i : seen) cout << " " << i;
    // cout << " " << h << endl;

    for (int i = 0; i < n; i++) {
        if (seen[i]) continue;
        seen[i] = true;
        for (int j = i+1; j < n; j++) {
            if (seen[j]) continue;
            seen[j] = true;
            
            if (lengths[i]+lengths[j] != h && h != -1) continue;

            // cout << i << j << endl;
            search(board+1, seen, lengths[i]+lengths[j]);

            seen[j] = false;
        }
        seen[i] = false;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    lengths = vector<int>(n);
    for (int& i : lengths) cin >> i;

    memo = vector<vector<int>>(n, vector<int>(4005));

    vector<bool> seen(n);
    search(0, seen, -1);

    cout << length << " " << nums;
}