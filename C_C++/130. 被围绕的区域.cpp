class Solution {
public:
    int r, c;
    void dfs(vector<vector<char>>& board, int x, int y) {
        if(x < 0 || x >= r || y < 0 || y >= c || board[x][y] == 'X' || board[x][y] == '-') return;
        board[x][y] = '-';
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++)
        {
            int newX = x + dx[i], newY = y + dy[i];
            dfs(board, newX, newY);
        }

    }

    void solve(vector<vector<char>>& board) {
        if(!board.size()) return;
        r = board.size(), c = board[0].size();
        for(int i = 0; i < r; i++)
        {
            dfs(board, i, 0);
            dfs(board, i, c-1);
        }
        for(int i = 1; i < c-1; i++)
        {
            dfs(board, 0, i);
            dfs(board, r-1, i);
        }
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
            {
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '-') board[i][j] = 'O';
            }
    }
};