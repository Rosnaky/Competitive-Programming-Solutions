#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

vector<vector<int>> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

void backtrack(vector<vector<int>>& board, int unknown, int row, int col) {
    if (row == board.size()) return;
    if (col == board[0].size()) return;
    
    if (unknown == 0) {
        for (auto& row : board) {
            for (auto& col : row) {
                cout << col << " ";
            }
            cout << endl;
        }
        exit(0);
    }

    if (board[row][col] != -1) {
        bool execute = false;
        for (vector<int> dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];

            if (newRow < 0 || newRow >= board.size() || newCol < 0 || newCol >= board[0].size()) continue;

            if (board[newRow][newCol] != -1) continue;

            if (newCol == 0) {
                if (board[newRow][newCol+1] != -1 && board[newRow][newCol+2] != -1) {
                    board[newRow][newCol] = board[newRow][newCol+1] - (board[newRow][newCol+2] - board[newRow][newCol+1]);
                    if (newRow == 0) {
                        if (board[newRow+1][newCol] != -1 && board[newRow+2][newCol] != -1 && board[newRow+2][newCol] - board[newRow+1][newCol] != board[newRow+1][newCol] - board[newRow][newCol]) {
                            board[newRow][newCol] = -1;
                            return;
                        }
                    }
                    else if (newRow == 1) {
                        if (board[newRow-1][newCol] != -1 && board[newRow+1][newCol] != -1 && board[newRow+1][newCol] - board[newRow][newCol] != board[newRow][newCol] - board[newRow-1][newCol]) {
                            board[newRow][newCol] = -1;
                            return;
                        }
                    }
                    else {
                        if (board[newRow-1][newCol] != -1 && board[newRow-2][newCol] != -1 && board[newRow-1][newCol] - board[newRow-2][newCol] != board[newRow][newCol] - board[newRow-1][newCol]) {
                            board[newRow][newCol] = -1;
                            return;
                        }
                    }
                    backtrack(board, unknown-1, newRow, newCol);
                    board[newRow][newCol] = -1;
                }
            }
            else if (newCol == 1) {
                if (board[newRow][newCol+1] != -1 && board[newRow][newCol-1] != -1) {
                    board[newRow][newCol] = board[newRow][newCol-1] + (board[newRow][newCol+1] - board[newRow][newCol-1]) / 2;
                    if (newRow == 0) {
                        if (board[newRow+1][newCol] != -1 && board[newRow+2][newCol] != -1 && board[newRow+2][newCol] - board[newRow+1][newCol] != board[newRow+1][newCol] - board[newRow][newCol]) {
                            board[newRow][newCol] = -1;
                            return;
                        }
                    }
                    else if (newRow == 1) {
                        if (board[newRow-1][newCol] != -1 && board[newRow+1][newCol] != -1 && board[newRow+1][newCol] - board[newRow][newCol] != board[newRow][newCol] - board[newRow-1][newCol]) {
                            board[newRow][newCol] = -1;
                            return;
                        }
                    }
                    else {
                        if (board[newRow-1][newCol] != -1 && board[newRow-2][newCol] != -1 && board[newRow-1][newCol] - board[newRow-2][newCol] != board[newRow][newCol] - board[newRow-1][newCol]) {
                            board[newRow][newCol] = -1;
                            return;
                        }
                    }
                    backtrack(board, unknown-1, newRow, newCol);
                    board[newRow][newCol] = -1;
                }
            }
            else {
                if (board[newRow][newCol-1] != -1 && board[newRow][newCol-2] != -1) {
                    board[newRow][newCol] = board[newRow][newCol-1] + (board[newRow][newCol-1] - board[newRow][newCol-2]);
                    if (newRow == 0) {
                        if (board[newRow+1][newCol] != -1 && board[newRow+2][newCol] != -1 && board[newRow+2][newCol] - board[newRow+1][newCol] != board[newRow+1][newCol] - board[newRow][newCol]) {
                            board[newRow][newCol] = -1;
                            return;
                        }
                    }
                    else if (newRow == 1) {
                        if (board[newRow-1][newCol] != -1 && board[newRow+1][newCol] != -1 && board[newRow+1][newCol] - board[newRow][newCol] != board[newRow][newCol] - board[newRow-1][newCol]) {
                            board[newRow][newCol] = -1;
                            return;
                        }
                    }
                    else {
                        if (board[newRow-1][newCol] != -1 && board[newRow-2][newCol] != -1 && board[newRow-1][newCol] - board[newRow-2][newCol] != board[newRow][newCol] - board[newRow-1][newCol]) {
                            board[newRow][newCol] = -1;
                            return;
                        }
                    }
                    backtrack(board, unknown-1, newRow, newCol);
                    board[newRow][newCol] = -1;
                }
            }


            if (newRow == 0) {
                if (board[newRow+1][newCol] != -1 && board[newRow+2][newCol] != -1) {
                    board[newRow][newCol] = board[newRow+1][newCol] - (board[newRow+2][newCol] - board[newRow+1][newCol]);
                    if (newCol == 0) {
                        if (board[newRow][newCol+1] != -1 && board[newRow][newCol+2] != -1 && board[newRow][newCol+2] - board[newRow][newCol+1] != board[newRow][newCol+1] - board[newRow][newCol]) {
                            board[newRow][newCol] = -1;
                            return;
                        }
                    }
                    else if (newCol == 1) {
                        if (board[newRow][newCol-1] != -1 && board[newRow][newCol+1] != -1 && board[newRow][newCol+1] - board[newRow][newCol] != board[newRow][newCol] - board[newRow][newCol-1]) {
                            board[newRow][newCol] = -1;
                            return;
                        }
                    }
                    else {
                        if (board[newRow][newCol-1] != -1 && board[newRow][newCol-2] != -1 && board[newRow][newCol-1] - board[newRow][newCol-2] != board[newRow][newCol] - board[newRow][newCol-1]) {
                            board[newRow][newCol] = -1;
                            return;
                        }
                    }
                    backtrack(board, unknown-1, newRow, newCol);
                    board[newRow][newCol] = -1;
                }
            }
            else if (newRow == 1) {
                if (board[newRow+1][newCol] != -1 && board[newRow-1][newCol] != -1) {
                    board[newRow][newCol] = board[newRow-1][newCol] + (board[newRow+1][newCol] - board[newRow-1][newCol]) / 2;
                    if (newCol == 0) {
                        if (board[newRow][newCol+1] != -1 && board[newRow][newCol+2] != -1 && board[newRow][newCol+2] - board[newRow][newCol+1] != board[newRow][newCol+1] - board[newRow][newCol]) {
                            board[newRow][newCol] = -1;
                            return;
                        }
                    }
                    else if (newCol == 1) {
                        if (board[newRow][newCol-1] != -1 && board[newRow][newCol+1] != -1 && board[newRow][newCol+1] - board[newRow][newCol] != board[newRow][newCol] - board[newRow][newCol-1]) {
                            board[newRow][newCol] = -1;
                            return;
                        }
                    }
                    else {
                        if (board[newRow][newCol-1] != -1 && board[newRow][newCol-2] != -1 && board[newRow][newCol-1] - board[newRow][newCol-2] != board[newRow][newCol] - board[newRow][newCol-1]) {
                            board[newRow][newCol] = -1;
                            return;
                        }
                    }
                    backtrack(board, unknown-1, newRow, newCol);
                    board[newRow][newCol] = -1;
                }
            }
            else {
                if (board[newRow-1][newCol] != -1 && board[newRow-2][newCol] != -1) {
                    board[newRow][newCol] = board[newRow-1][newCol] + (board[newRow-1][newCol] - board[newRow-2][newCol]);
                    if (newCol == 0) {
                        if (board[newRow][newCol+1] != -1 && board[newRow][newCol+2] != -1 && board[newRow][newCol+2] - board[newRow][newCol+1] != board[newRow][newCol+1] - board[newRow][newCol]) {
                            board[newRow][newCol] = -1;
                            return;
                        }
                    }
                    else if (newCol == 1) {
                        if (board[newRow][newCol-1] != -1 && board[newRow][newCol+1] != -1 && board[newRow][newCol+1] - board[newRow][newCol] != board[newRow][newCol] - board[newRow][newCol-1]) {
                            board[newRow][newCol] = -1;
                            return;
                        }
                    }
                    else {
                        if (board[newRow][newCol-1] != -1 && board[newRow][newCol-2] != -1 && board[newRow][newCol-1] - board[newRow][newCol-2] != board[newRow][newCol] - board[newRow][newCol-1]) {
                            board[newRow][newCol] = -1;
                            return;
                        }
                    }
                    backtrack(board, unknown-1, newRow, newCol);
                    board[newRow][newCol] = -1;
                }
            }
            


            for (int i = 0; i < 1000; i++) {
        


                if (newRow >= 0 && newRow < 3 && newCol >= 0 && newCol < 3) {
                    execute = true;
                    int newVal = i + board[row][col];

                    if (newCol == 0) {
                        if (board[newRow][newCol+1] != -1 && board[newRow][newCol+2] != -1 && board[newRow][newCol+2] - board[newRow][newCol+1] != board[newRow][newCol+1] - newVal) {
                            continue;
                        }
                    }
                    else if (newCol == 1) {
                        if (board[newRow][newCol-1] != -1 && board[newRow][newCol+1] != -1 && board[newRow][newCol+1] - newVal != newVal - board[newRow][newCol-1]) {
                            continue;
                        }
                    }
                    else {
                        if (board[newRow][newCol-1] != -1 && board[newRow][newCol-2] != -1 && board[newRow][newCol-1] - board[newRow][newCol-2] != newVal - board[newRow][newCol-1]) {
                            continue;
                        }
                    }
                    if (newRow == 0) {
                        if (board[newRow+1][newCol] != -1 && board[newRow+2][newCol] != -1 && board[newRow+2][newCol] - board[newRow+1][newCol] != board[newRow+1][newCol] - newVal) {
                            continue;
                        }
                    }
                    else if (newRow == 1) {
                        if (board[newRow-1][newCol] != -1 && board[newRow+1][newCol] != -1 && board[newRow+1][newCol] - newVal != newVal - board[newRow-1][newCol]) {
                            continue;
                        }
                    }
                    else {
                        if (board[newRow-1][newCol] != -1 && board[newRow-2][newCol] != -1 && board[newRow-1][newCol] - board[newRow-2][newCol] != newVal - board[newRow-1][newCol]) {
                            continue;
                        }
                    }
                    
                    board[newRow][newCol] = newVal;
                    backtrack(board, unknown-1, newRow, newCol);
                    board[newRow][newCol] = -1;
                }
            }
        }
        if (!execute) {
            if (row != board.size()-1) {
                backtrack(board, unknown, row+1, 0);
            }
            if (col != board[0].size()-1) {
                backtrack(board, unknown, row, col+1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> board(3, vector<int>(3));
    int unknowns = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            string temp;
            cin >> temp;
            if (isdigit(temp[0])) {
                board[i][j] = stoi(temp);
            }
            else {
                board[i][j] = -1;
                unknowns++;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            backtrack(board, unknowns, i, j);
        }
    }
}