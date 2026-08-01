class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> dist(r, vector<int>(c, 0));
        vector<vector<bool>> vis(r, vector<bool>(c, false));
        queue<pair<int, int>> q1;
        queue<pair<int, int>> q2;
        bool island_found = false;
        for (int i = 0 ; i < r ; i ++) {
            if(island_found) break;
            for (int j = 0 ; j < c ; j ++) {
                if (grid[i][j] == 1 and !island_found) {
                    island_found = true;
                    vis[i][j] = true;
                    q1.push({i, j});
                    while(!q1.empty()) {
                        auto[x, y] = q1.front();
                        q2.push({x, y});
                        q1.pop();
                        for (int i = 0 ; i < 4 ;i ++) {
                            int nx = x + dx[i];
                            int ny = y + dy[i];
                            if(nx >= 0 and nx < r and ny >= 0 and ny < c and grid[nx][ny] == 1 and !vis[nx][ny]) {
                                q1.push({nx, ny});
                                vis[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        }
        while(!q2.empty()) {
            auto[x, y] = q2.front();
            q2.pop();
            for (int i = 0 ; i < 4 ; i ++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 and nx < r and ny >= 0 and ny < c and grid[nx][ny] == 0 and !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    dist[nx][ny] = dist[x][y] + 1;
                    q2.push({nx, ny});
                }
                else if(nx >= 0 and nx < r and ny >= 0 and ny < c and grid[nx][ny] == 1 and !vis[nx][ny]) {
                    return dist[x][y];
                }
            }
        }
        return 0;
    }
};