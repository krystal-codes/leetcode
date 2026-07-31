class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> dist(r, vector<int>(c, 0));
        queue<pair<int,int>> q;
        q.push({0,0});
        dist[0][0] = 1;
        if(grid[0][0] == 1 or grid[r - 1][c - 1] == 1) return -1;
        if(r == 1 and c == 1) {
            return (grid[0][0] == 0) ? 1 : -1;
        }
        while(!q.empty()) {
            auto[x, y] = q.front();
            q.pop();
            for(int i = 0 ; i < 8 ; i ++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx == r - 1 and ny == c - 1) {
                    return dist[x][y] + 1;
                }
                if(nx >= 0 and nx < r and ny >= 0 and ny < c and grid[nx][ny] == 0 and !dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
        return -1;
    }
};