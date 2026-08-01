class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r = board.size();
        int c = board[0].size();
        vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
        int cr = click[0];
        int cc = click[1];
        if(board[cr][cc] == 'M') {
            board[cr][cc] = 'X';
            return board;
        }
        vector<vector<bool>> vis(r, vector<bool>(c, false));
        queue<pair<int, int>> q;
        q.push({cr, cc});
        vis[cr][cc] = true;
        while(!q.empty()) {
            auto[x, y] = q.front();
            q.pop();
            vis[x][y] = true;
            int mine_count = 0;
            bool mine_found = false;
            for (int i = 0 ; i < 8 ; i ++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 and nx < r and ny >= 0 and ny < c) {
                    if(board[nx][ny] == 'M') {
                        mine_count ++;
                        mine_found = true;
                    }
                }
            }
            if(!mine_found) {
                    board[x][y] = 'B';
                    for (int i = 0 ; i < 8 ; i ++) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if(nx >= 0 and nx < r and ny >= 0 and ny < c and !vis[nx][ny]) {
                            q.push({nx, ny});
                            vis[nx][ny] = true;
                        }
                    }
                }
            else board[x][y] = char(mine_count) + '0';
        }
        return board;
    }
};