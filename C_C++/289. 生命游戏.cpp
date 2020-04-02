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