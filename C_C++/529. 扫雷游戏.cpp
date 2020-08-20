class Solution {
public:
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0], y = click[1];
        if(board[x][y] == 'M') board[x][y] = 'X';
        else dfs(board, x, y);
        return board;
    }
    void dfs(vector<vector<char>>& board, int r, int c){
        int cnt = 0;
        for(int i = 0; i < 8; i++)
        {
            int x = r + dx[i];
            int y = c + dy[i];
            if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) continue;
            if(board[x][y] == 'M') cnt++;
        }
        if(cnt){
            board[r][c] = '0' + cnt;
            return;
        }
        board[r][c] = 'B';
        for(int i = 0; i < 8; i++)
        {
            int x = r + dx[i];
            int y = c + dy[i];
            if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != 'E') continue;
            dfs(board, x, y);
        }
    }
};