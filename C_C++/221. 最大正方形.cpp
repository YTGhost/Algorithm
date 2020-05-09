class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix){
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix.front().size();
        int max = 0;
        int dp[m][n];
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 || j == 0)    dp[i][j] = matrix[i][j] - '0';
                else if(matrix[i][j] == '1'){
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                }else{
                    dp[i][j] = 0;
                }
                max = std::max(max, dp[i][j]);
            }
        }
        return max*max;
    }
};

// 2020/05/08重做
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size();
        if(r == 0) return 0;
        int c = matrix[0].size();
        int maxArea = 0;
        vector<vector<int>> dp(r, vector<int>(c, 0));
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
            {
                if(i == 0 || j == 0) dp[i][j] = matrix[i][j] - '0';
                else if(matrix[i][j] == '1') dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                maxArea = max(maxArea, dp[i][j]);
            }
        return maxArea * maxArea;
    }
};