#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int n;
vector<vector<bool>> grid;
vector<vector<bool>> seen;
int ansP = 0, ansA = 0;

pair<int, int> dfs(int i, int j) {
    if (!(i >= n || i < 0 || j >= n || j < 0) && seen[i][j])  return {0, 0};
    if (i >= n || i < 0 || j >= n || j < 0 || !grid[i][j])  return {0, 1};

    seen[i][j] = true;

    int a = 1, p = 0;
    
    pair<int, int> temp = dfs(i-1, j); a += temp.first, p += temp.second;
    temp = dfs(i+1, j); a += temp.first, p += temp.second;
    temp = dfs(i, j-1); a += temp.first, p += temp.second;
    temp = dfs(i, j+1); a += temp.first, p += temp.second;

    return {a, p};
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);


    cin >> n;
    grid = vector<vector<bool>>(n, vector<bool>(n));
    seen = vector<vector<bool>>(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '.') grid[i][j] = 0;
            else grid[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!grid[i][j]) continue;
            auto [a, p] = dfs(i, j);
            if (a > ansA) {
                ansA = a, ansP = p;
            }
            else if (a == ansA && p < ansP) {
                ansP = p;
            }
        }
    }

    cout << ansA << " " << ansP;
}