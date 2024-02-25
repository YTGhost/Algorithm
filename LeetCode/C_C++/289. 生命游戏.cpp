class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // live -> dead: -1, dead -> live: 2, live -> live: 1, dead -> dead: 0
        int m = board.size(), n = board[0].size();
        int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
        function<void(int, int)> handle = [&](int x, int y) -> void {
            int cnt = 0;
            for(int i = 0; i < 8; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    continue;
                }
                if(board[nx][ny] == 1 || board[nx][ny] == -1) {
                    cnt++;
                }
            }
            if((cnt < 2 || cnt > 3) && board[x][y] == 1) {
                board[x][y] = -1;
            }
            if(cnt == 3 && board[x][y] == 0) {
                board[x][y] = 2;
            }
        };
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                handle(i, j);
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == -1) {
                    board[i][j] = 0;
                } else if(board[i][j] == 2) {
                    board[i][j] = 1;
                }
            }
        }
    }
};

class Solution {
public:
    int count(vector<vector<int>>& board, int i , int j){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == 0){
            return 0;
        }
        return 1;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int p1[] = {0, 1, 1, 1, 0, -1, -1, -1};
        int p2[] = {1, 1, 0, -1, -1, -1, 0, 1};
        int t[board.size()][board[0].size()];
        memset(t, 0, sizeof t);
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                for(int k = 0; k < 8; k++)
                    t[i][j] += count(board, i + p1[k], j + p2[k]);

        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == 1){
                    if(t[i][j] < 2 || t[i][j] > 3) board[i][j] = 0;
                }else{
                    if(t[i][j] == 3) board[i][j] = 1;
                }
            }
    }
};