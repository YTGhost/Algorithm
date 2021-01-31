class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> res(4);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(i) matrix[i][j] += matrix[i-1][j];
        int maxSum = INT_MIN;
        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++)
            {
                int last = 0;
                int t = 0;
                for(int k = 0; k < m; k++)
                {
                    if(0 > last) t = k;
                    last = max(last, 0) + matrix[j][k] - (i == 0 ? 0 : matrix[i-1][k]);
                    if(last > maxSum) {
                        maxSum = last;
                        res[0] = i, res[1] = t, res[2] = j, res[3] = k;
                    }
                }
            }
        return res;
    }
};