class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int p1[4] = {1, -1, 0, 0};
        int p2[4] = {0, 0, 1, -1};
        int count = 0;
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
            {
                if(board[i][j] == 'R'){
                    for(int k = 0; k < 4; k++)
                    {
                        int x = i, y = j;
                        while(true){
                            x += p1[k];
                            y += p2[k];
                            if(x >= 8 || y >=8 || x < 0 || y < 0 || board[x][y] == 'B'){
                                break;
                            }
                            if(board[x][y] == 'p'){
                                count++;
                                break;
                            }
                        }
                    }
                }
            }
        return count;
    }
};