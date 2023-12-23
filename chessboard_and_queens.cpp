#include <unordered_set>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

int backtrack(int row, unordered_set<int>& cols, unordered_set<int>& diags, unordered_set<int>& antiDiags, vector<string>& board) {
    if (row == 8) {
        return 1;
    }

    int count = 0;
    for (int col = 0; col < 8; col++) {
        if (board[row][col] == '*' || cols.count(col) || diags.count(row - col) || antiDiags.count(row + col)) {
            continue;
        }

        cols.insert(col);
        diags.insert(row - col);
        antiDiags.insert(row + col);

        count += backtrack(row + 1, cols, diags, antiDiags, board);

        cols.erase(col);
        diags.erase(row - col);
        antiDiags.erase(row + col);
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<string> board(8);
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }

    unordered_set<int> cols, diags, antiDiags;

    cout << backtrack(0, cols, diags, antiDiags, board);
}