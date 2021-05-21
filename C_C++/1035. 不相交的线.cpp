class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> f(n+1, vector<int>(m+1));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                f[i][j] = max(f[i][j-1], f[i-1][j]);
                if(nums1[i-1] == nums2[j-1]) {
                    f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
                }
            }
        }
        return f[n][m];
    }
};