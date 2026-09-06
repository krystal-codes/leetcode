class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        const int INF = 1e9;
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<vector<int>>>> dist(r, vector<vector<vector<int>>> (c, vector<vector<int>> (k + 1, vector<int> (5, INF))));
        dist[0][0][0][4] = grid[0][0];
        priority_queue<tuple<int, int, int, int, int>, vector<tuple<int, int, int, int, int>>, greater<tuple<int, int, int, int, int>>> pq;
        /*
        dist, turns, last turn, x, y 
        */
        pq.push({grid[0][0], 0, 4, 0, 0});
        while(!pq.empty()) {
            auto[distance, turns, lastTurn, x, y] = pq.top();
            pq.pop();
            if (x == r - 1 and y == c - 1) {
                return dist[x][y][turns][lastTurn];
            }
            if(dist[x][y][turns][lastTurn] < distance) continue;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 and nx < r and ny >= 0 and ny < c) {
                    int newDist = dist[x][y][turns][lastTurn] + grid[nx][ny];
                    if (lastTurn == i or lastTurn == 4) {
                        if (dist[nx][ny][turns][i] > newDist) {
                            dist[nx][ny][turns][i] = newDist;
                            pq.push({newDist, turns, i, nx, ny});
                        }
                    }
                    else if (lastTurn != i) {
                        int newTurns = turns + 1;
                        if (newTurns <= k) {
                            if (dist[nx][ny][newTurns][i] > newDist) {
                                dist[nx][ny][newTurns][i] = newDist;
                                pq.push({newDist, newTurns, i, nx, ny});
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};