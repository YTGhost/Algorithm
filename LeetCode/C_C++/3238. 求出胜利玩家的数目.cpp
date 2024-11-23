class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> cnt(n, vector<int>(11));
        for (int i = 0; i < pick.size(); i++) {
            cnt[pick[i][0]][pick[i][1]]++;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 10; j++) {
                if (cnt[i][j] > i) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};