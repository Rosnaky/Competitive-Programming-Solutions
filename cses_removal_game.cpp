#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int n;
vector<int> nums;
vector<vector<vector<int>>> memo;

int solve(int left, int right, int score, bool turn) {
    if (left > right) return score;
    if (memo[left][right][turn] != -1e9) return memo[left][right][turn];

    if (turn) return max(solve(left+1, right, score+nums[left], false), solve(left, right-1, score+nums[right], false));

    return memo[left][right][turn] = min(solve(left+1, right, score, true), solve(left, right-1, score, true));
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    nums = vector<int>(n);
    for (int& i : nums) cin >> i;

    vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(2, -1e9)));

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            
        }
    }
}