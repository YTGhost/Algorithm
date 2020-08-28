class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for(int i = 0; i < moves.length(); i++)
        {
            if(moves[i] == 'U') y++;
            else if(moves[i] == 'D') y--;
            else if(moves[i] == 'L') x--;
            else x++;
        }
        return x == y ? x == 0 : false;
    }
};