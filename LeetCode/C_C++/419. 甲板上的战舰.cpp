class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        int res = 0;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        function<void(int, int)> dfs = [&](int x, int y) {
            visited[x][y] = true;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'X' && !visited[nx][ny]) {
                    dfs(nx, ny);
                }
            }
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X' && !visited[i][j]) {
                    res++;
                    dfs(i, j);
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size(), m =  board[0].size(), res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i > 0 && board[i-1][j] == 'X') continue;
                if(j > 0 && board[i][j-1] == 'X') continue;
                if(board[i][j] == 'X') res++;
            }
        }
        return res;
    }
};