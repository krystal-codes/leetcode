class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        int r = maze.size();
        int c = maze[0].size();
        vector<vector<int>> dist(r, vector<int> (c, 0));
        vector<vector<bool>> exit(r, vector<bool> (c, false));
        for (int i = 0; i < c; i++) {
            if (maze[0][i] == '.') exit[0][i] = true;
        }
        for (int i = 0; i < c; i++) {
            if (maze[r - 1][i] == '.') exit[r - 1][i] = true;
        }
        for (int i = 0; i < r; i++) {
            if (maze[i][0] == '.') exit[i][0] = true;
        }
        for (int i = 0; i < r; i++) {
            if (maze[i][c - 1] == '.') exit[i][c - 1] = true;
        }
        int sx = entrance[0];
        int sy = entrance[1];
        queue<pair<int, int>> q;
        q.push({sx, sy});
        while(!q.empty()) {
            auto[x, y] = q.front();
            q.pop();
            if(exit[x][y] == true and (x != sx or y != sy)) return dist[x][y];
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 and nx < r and ny >= 0 and ny < c and maze[nx][ny] == '.') {
                    if(!dist[nx][ny]) {
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return -1;
    }
};