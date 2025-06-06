// C++ implementation for Matrix Islands
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& grid, int i, int j) {
    int n = grid.size(), m = grid[0].size();
    if (i<0 || j<0 || i>=n || j>=m || grid[i][j]==0) return;

    grid[i][j] = 0;
    for (int dx = -1; dx <= 1; dx++)
        for (int dy = -1; dy <= 1; dy++)
            if (dx != 0 || dy != 0)
                dfs(grid, i+dx, j+dy);
}

int countIslands(vector<vector<int>> grid) {
    int count = 0;
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
            if (grid[i][j] == 1) {
                dfs(grid, i, j);
                count++;
            }
    return count;
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {1, 0, 0, 1}
    };
    cout << "Total Islands (Diagonal included): " << countIslands(grid) << endl;
    return 0;
}
