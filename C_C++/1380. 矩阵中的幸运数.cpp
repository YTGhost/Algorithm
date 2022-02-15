class Solution {
public:
    int row[55], col[55]; 
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++) {
            row[i] = 1e5 + 5;
            for(int j = 0; j < m; j++) {
                row[i] = min(row[i], matrix[i][j]);
                col[j] = max(col[j], matrix[i][j]);
            }
        }
        vector<int> res;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(row[i] == matrix[i][j] && col[j] == matrix[i][j]) {
                    res.push_back(matrix[i][j]);
                }
            }
        }
        return res;
    }
};