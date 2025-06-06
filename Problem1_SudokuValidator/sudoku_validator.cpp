// C++ implementation for Sudoku Validator
#include <bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board, vector<vector<pair<int, int>>>& zones) {
    vector<unordered_set<char>> rows(9), cols(9), boxes(9);
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            char c = board[i][j];
            if (c == '.') continue;
            int boxIdx = (i / 3) * 3 + (j / 3);
            if (rows[i].count(c) || cols[j].count(c) || boxes[boxIdx].count(c))
                return false;
            rows[i].insert(c);
            cols[j].insert(c);
            boxes[boxIdx].insert(c);
        }

    for (auto& zone : zones) {
        unordered_set<char> seen;
        for (auto& it : zone) {
            char c = board[it.first][it.second];
            if (c == '.') continue;
            if (seen.count(c)) return false;
            seen.insert(c);
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    // Sample Custom Zone: Top-left 3x3 block
    vector<vector<pair<int, int>>> zones = {
        {{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}}
    };

    cout << "Sudoku is " << (isValidSudoku(board, zones) ? "Valid" : "Invalid") << endl;
    return 0;
}
