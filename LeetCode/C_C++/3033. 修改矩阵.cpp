class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        vector<int> maxCol(n);
        for(int i = 0; i < n; i++) {
            int maxVal = -1;
            for(int j = 0; j < m; j++) {
                maxVal = max(maxVal, matrix[j][i]);
            }
            maxCol[i] = maxVal;
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == -1) {
                    res[i][j] = maxCol[j];
                } else {
                    res[i][j] = matrix[i][j];
                }
            }
        }
        return res;
    }
};