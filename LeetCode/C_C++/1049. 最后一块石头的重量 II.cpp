class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for(auto stone : stones) sum += stone;
        int t = sum / 2;
        vector<vector<int>> f(n + 1, vector<int>(t + 1));
        for(int i = 1; i <= n; i++) {
            int stone = stones[i-1];
            for(int j = 0; j <= t; j++) {
                f[i][j] = f[i-1][j];
                if(j >= stone) f[i][j] = max(f[i][j], f[i-1][j-stone] + stone);
            }
        }
        return sum - 2 * f[n][t];
    }
};