class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> mask(m);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                mask[i] |= matrix[i][j] << j;
            }
        }
        int res = 0;
        for(int subset = 0; subset < (1 << n); subset++) {
            if(__builtin_popcount(subset) == numSelect) {
                int cnt = 0;
                for(auto row : mask) {
                    if((row & subset) == row) {
                        cnt++;
                    }
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
};