class Solution {
    public:
        int maxDistance(vector<vector<int>>& arrays) {
            int mn = INT_MAX / 2, mx = INT_MIN / 2, res = 0;
            for (auto& a : arrays) {
                res = max({res, a.back() - mn, mx - a[0]});
                mn = min(mn, a[0]);
                mx = max(mx, a.back());
            }
            return res;
        }
    };