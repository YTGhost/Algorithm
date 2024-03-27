class Solution {
public:
    const int MOD = 1e9 + 7;
    int countWays(vector<vector<int>>& ranges) {
        int n = ranges.size();
        sort(ranges.begin(), ranges.end());
        int res = 1, r = -1;
        for(int i = 0; i < n; i++) {
            if(ranges[i][0] > r) {
                res =  res * 2 % MOD;
            }
            r = max(r, ranges[i][1]);
        }
        return res;
    }
};