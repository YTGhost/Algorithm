class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefixSum(n + 1);
        partial_sum(stones.begin(), stones.end(), prefixSum.begin() + 1);
        vector<vector<int>> f(n, vector<int>(n));
        for(int i = n - 2; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                f[i][j] = max(prefixSum[j + 1] - prefixSum[i + 1] - f[i + 1][j], prefixSum[j] - prefixSum[i] - f[i][j - 1]);
            }
        }
        return f[0][n - 1];
    }
};