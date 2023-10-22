class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> f(n + 1, vector<int>(n + 1));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                f[i][j] = f[i - 1][j - 1] + j * satisfaction[i - 1];
                if(i > j) {
                    f[i][j] = max(f[i][j], f[i - 1][j]);
                }   
            }
        }
        int res = 0;
        for(int i = 0; i <= n; i++) {
            res = max(res, f[n][i]);
        }
        return res;
    }
};