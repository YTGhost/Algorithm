// 一维dp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        vector<int> f(size+2, INT_MAX);
        f[1] = triangle[0][0];
        for(int i = 2; i <= size; i++)
        {
            f[0] = f[i+1] = INT_MAX;
            for(int j = i; j >= 1; j--)
                f[j] = min(f[j-1], f[j]) + triangle[i-1][j-1];
        }
        int res = INT_MAX;
        for(int i = 1; i <= size; i++) res = min(res, f[i]);
        return res;
    }
};

// 二维dp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        vector<vector<int>> f(size+1, vector<int>(size+1, INT_MAX));
        f[1][1] = triangle[0][0];
        for(int i = 2; i <= size; i++)
            for(int j = 1; j <= i; j++)
                f[i][j] = min(f[i-1][j-1], f[i-1][j]) + triangle[i-1][j-1];
        int res = INT_MAX;
        for(int i = 1; i <= size; i++) res = min(res, f[size][i]);
        return res;
    }
};