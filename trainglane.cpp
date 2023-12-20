#include <vector>
#include <iostream>
#include <set>

using namespace std;

set<vector<int>> seen;
vector<vector<int>> graph;
int n;

int dp(int row, int col) {
    if (seen.find({row, col}) != seen.end()) {
        return 0;
    }
    if (row >= 2 || col >= n || row < 0 || col < 0) {
        return 0;
    }
    if (graph[row][col] == 0) {
        return 0;
    }

    seen.insert({row, col});
    int ans = 1 + dp(row + 1, col) + dp(row - 1, col);

    if (col % 2 == 0) {
        ans += dp(row, col+1) + dp(row, col-1);
    }
    if (n % 2 == 0 && (col == n-1 && (seen.find({0, col}) == seen.end() && seen.find({1, col}) == seen.end()))) {
        ans += 1;
    }
    return ans;
}

int main() {
    
    cin >> n;
    
    graph = vector<vector<int>>(2, vector<int>(n, 0));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int ans = 0;
    int tape = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            ans = dp(i, j);
            if (ans > 0) {
                tape += ans + 2;
            }
        }
    }

    cout << tape;
}