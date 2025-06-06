// C++ implementation for Knights and Portals
#include <bits/stdc++.h>
using namespace std;
int minStepsWithTeleport(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<tuple<int, int, int, bool>> q;
    vector<pair<int, int>> teleports;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (grid[i][j] == 0)
                teleports.push_back({i, j});

    q.push({0, 0, 0, false});
    visited[0][0] = true;
    vector<pair<int, int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};

    while (!q.empty()) {
        tuple<int, int, int, bool> curr = q.front();
        int x = get<0>(curr);
        int y = get<1>(curr);
        int steps = get<2>(curr);
        bool used = get<3>(curr);
        q.pop();
        if (x == n-1 && y == m-1) return steps;

        for (auto it : dirs) {
            auto dx=it.first;
            auto dy=it.second;
            int nx = x + dx, ny = y + dy;
            if (nx>=0 && ny>=0 && nx<n && ny<m && !visited[nx][ny] && grid[nx][ny]==0) {
                visited[nx][ny] = true;
                q.push({nx, ny, steps+1, used});
            }
        }

        if (!used && grid[x][y] == 0) {
            for (auto it : teleports) {
                auto tx=it.first;
                auto ty=it.second;
                if (!visited[tx][ty]) {
                    visited[tx][ty] = true;
                    q.push({tx, ty, steps+1, true});
                }
            }
        }
    }

    return -1;
}

int main() {
    vector<vector<int>> grid = {
        {0, 1, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    cout << "Shortest path with one teleport: " << minStepsWithTeleport(grid) << endl;
    return 0;
}
