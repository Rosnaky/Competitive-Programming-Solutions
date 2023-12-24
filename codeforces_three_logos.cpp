#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int length = 0;

bool full(vector<vector<int>>& grid) {
    for (vector<int>& row : grid) {
        for (int col : row) {
            if (col == -1) return false;
        }
    }
    return true;
}

bool fits(vector<vector<int>>& grid, int w, int h, int row, int col) {
    for (int i = row; i < row+h; i++) {
        for (int j = col; j < col+w; j++) {
            if (grid[i][j] != -1) {
                return false;
            }
        }
    }
    return true;
}


void backtrack(vector<vector<int>>& grid, vector<vector<pair<int, int>>>& logos, int index) {
    if (index == 3 && full(grid)) {
        cout << length << "\n";
        for (vector<int>& row : grid) {
            for (int col : row) {
                if (col == 0) {
                    cout << "A";
                }
                else if (col == 1) {
                    cout << "B";
                }
                else if (col == 2) {
                    cout << "C";
                }
            }
            cout << "\n";
        }
        exit(0);
    }
    if (index == 3) return;

    for (vector<int>& row : grid) {
        for (int col : row) {
            if (col == 0) {
                cout << "A";
            }
            else if (col == 1) {
                cout << "B";
            }
            else if (col == 2) {
                cout << "C";
            }
            else {
                cout << 0;
            }
        }
        cout << "\n";
    }
    cout << endl << endl;


    for (pair<int, int>& logo: logos[index]) {
        int width = logo.first, height = logo.second;

        for (int i = 0; i <= length-height; i++) {
            for (int j = 0; j <= length-width; j++) {

                if (fits(grid, width, height, i, j)) {

                    for (int k = i; k < i+height; k++) {
                        for (int l = j; l < j+width; l++) {
                            grid[k][l] = index;
                        }
                    }
                    backtrack(grid, logos, index+1);
                    for (int k = i; k < i+height; k++) {
                        for (int l = j; l < j+width; l++) {
                            grid[k][l] = -1;
                        }
                    }

                }
            }
        }
    }
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<pair<int, int>>> logos(3);

    for (int i = 0; i < 3; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        logos[i].push_back({temp1, temp2});
        logos[i].push_back({temp2, temp1});
        length = max(length, max(temp1, temp2));
    }

    vector<vector<int>> grid(length, vector<int>(length, -1));
    backtrack(grid, logos, 0);
    cout << -1;
}