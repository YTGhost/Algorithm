class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int res = INT_MIN;
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++)
        {
            vector<int> sum(m);
            for(int j = i; j < n; j++)
            {
                for(int c = 0; c < m; c++)
                {
                    sum[c] += matrix[j][c];
                }
                set<int> sumSet{0};
                int s = 0;
                for(int v : sum)
                {
                    s += v;
                    auto lb = sumSet.lower_bound(s - k);
                    if(lb != sumSet.end()) {
                        res = max(res, s - *lb);
                    }
                    sumSet.insert(s);
                }
            }
        }
        return res;
    }
};