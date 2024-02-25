class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> f(n+1, vector<int>(m+1, INT_MIN));

        for(int i = 0; i <= n; i++) f[i][0] = 0;
        for(int i = 0; i <= m; i++) f[0][i] = 0;

        int res = INT_MIN;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                f[i][j] = max(f[i-1][j], f[i][j-1]);
                int t = f[i-1][j-1] + nums1[i-1] * nums2[j-1];
                res = max(res, t);
                f[i][j] = max(f[i][j], t);
            }
        return res;
    }
};