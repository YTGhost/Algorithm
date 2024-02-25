class NumMatrix {
public:
    vector<vector<int>> pre;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 1; i < n; i++) {
            matrix[i][0] += matrix[i - 1][0];
        }
        for(int i = 1; i < m; i++) {
            matrix[0][i] += matrix[0][i - 1];
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                matrix[i][j] += matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1];
            }
        }
        pre = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = pre[row2][col2];
        if(row1) res -= pre[row1 - 1][col2];
        if(col1) res -= pre[row2][col1 - 1];
        if(row1 && col1) res += pre[row1 - 1][col1 - 1];
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */