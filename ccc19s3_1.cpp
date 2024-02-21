#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    vector<vector<int>> grid(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            string x; cin >> x;
            if (isdigit(x[0])) {
                grid[i][j] = stoi(x);
            }
            else grid[i][j] = -1;
        }
    }

    
}