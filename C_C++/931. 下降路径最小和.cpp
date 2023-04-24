class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int t = matrix[i-1][j];
                if(j > 0) t = min(t, matrix[i-1][j-1]);
                if(j < n - 1) t = min(t, matrix[i-1][j+1]);
                matrix[i][j] += t;
            }
        }
        int res = INT_MAX;
        for(int i = 0; i < n; i++) {
            res = min(res, matrix[n-1][i]);
        }
        return res;
    }
};