#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

void updatePossible(vector<vector<int>>& grid, vector<vector<map<int, bool>>>& possible, int i, int j, bool newVal);

bool solved(vector<vector<int>>& grid) {
    for (auto& v : grid) {
        for (int i : v)  {
            if (i == -1) return 0;
        }
    }
    return 1;
}

bool divisible (vector<vector<int>>& grid, int a) {
    for (int i = 0; i < grid.size(); i++) {
        int curr = 0;
        for (int j = 0; j < grid[0].size(); j++) {
            curr*=10;
            curr += grid[i][j];
        }

        if (curr%a) return 0;
    }
    return 1;
}

int findGcd(vector<vector<int>>& grid) {
    vector<int> nums;
    for (int i = 0; i < grid.size(); i++) {
        int curr = 0;
        for (int j = 0; j < grid[0].size(); j++) {
            curr*=10;
            curr += grid[i][j];
        }

        nums.push_back(curr);
    }

    sort(nums.begin(), nums.end());

    for (int i = sqrt(nums[0]); i >= 1; i--) {
        bool good = 1;
        for (int num : nums) {
            if (num%i) {
                good = 0;
                break;
            }
        }

        if (good) {
            return i;
        }
    }

    return -1;
}

int solve(vector<vector<int>>& grid, vector<int>& valid, vector<vector<map<int, bool>>>& possible, vector<int>& set) {
    // for (auto& v : grid) {
    //     for (auto i : v) {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // } cout << endl;

    if (solved(grid)) {

        for (int a : valid) {
            if (divisible(grid, a)) {
                    
                    for (auto& v : grid) {
                        for (auto i : v) {
                            cout << i << " ";
                        }
                        cout << endl;
                    } cout << endl;

                int gcd = findGcd(grid);
                return gcd;
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        bool good = 1;
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == -1) {
                good = 0;
                break;
            }
        }

        if (!good) continue;

        int curr = 0;
        for (int j = 0; j < grid[0].size(); j++) {
            curr*=10;
            curr += grid[i][j];
        }
        for (int v : valid) {
            if (!(curr%v)) {
                good = 0;
            }
        }
        
        if (good) {
            return -1;
        }

        for (auto& v : grid) {
            for (auto i : v) {
                cout << i << " ";
            }
            cout << endl;
        } cout << endl;

    }

    bool good = 1;
    int ans = 1;
    for (int i = 0; i < 9 && good; i++) {
        for (int j = 0; j < 9 && good; j++) {
            if (grid[i][j] == -1) {
                good = 0;

                for (int n : set) {
                    if (!possible[i][j][n]) continue;
                    grid[i][j] = n;
                    updatePossible(grid, possible, i, j, 0);
                    
                    int res = solve(grid, valid, possible, set);
                    updatePossible(grid, possible, i, j, 1);
                    grid[i][j] = -1;

                    ans = max(ans, res);
                }
            }
        }
    }

    return ans;

}

void updatePossible(vector<vector<int>>& grid, vector<vector<map<int, bool>>>& possible, int i, int j, bool newVal) {
    for (int k = 0; k < 9; k++) {
        possible[i][k][grid[i][j]] = newVal; 
        possible[k][j][grid[i][j]] = newVal; 
    }
    for (int k = (i/3)*3; k < (i/3)*3 + 3; k++) {
        for (int l = (j/3)*3; l < (j/3)*3+3; l++) {
            possible[k][l][grid[i][j]] = newVal;
        }
    }
}


int main() {

    vector<vector<int>> grid(9, vector<int>(9, -1));

    grid[0][7] = 2;
    grid[1][8] = 5;
    grid[2][1] = 2;
    grid[3][2] = 0;
    grid[5][3] = 2;
    grid[6][4] = 0;
    grid[7][5] = 2;
    grid[8][6] = 5;

    

    vector<vector<map<int, bool>>> possible(9, vector<map<int,bool>>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9; k++) {
                possible[i][j][k] = 1;
            }
        }
    }
    // return 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] != -1) {
                updatePossible(grid, possible, i, j, 0);
            }
        }
    }

    vector<int> set = {1, 2, 3, 4, 5, 6, 7, 8, 0};

    vector<int> valid = {3, 7, 9};

    int ans = solve(grid, valid, possible, set);

    cout << ans << '\n';
}