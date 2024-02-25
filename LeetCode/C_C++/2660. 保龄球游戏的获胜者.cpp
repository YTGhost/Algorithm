class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int n = player1.size();
        int score1 = 0, score2 = 0;
        for(int i = 0; i < n; i++) {
            int a = i - 2 < 0 ? 0 : i - 2;
            int b = i - 1 < 0 ? 0 : i - 1;
            if(player1[a] == 10 && a != i || player1[b] == 10 && b != i) {
                score1 += player1[i] * 2;
            } else {
                score1 += player1[i];
            }
            if(player2[a] == 10 && a != i || player2[b] == 10 && b != i) {
                score2 += player2[i] * 2;
            } else {
                score2 += player2[i];
            }
            cout << score2 << endl;
        }
        int res = 0;
        if(score1 > score2) res = 1;
        else if(score2 > score1) res = 2;
        return res;
    }
};