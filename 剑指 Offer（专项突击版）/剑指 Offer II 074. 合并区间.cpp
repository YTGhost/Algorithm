class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int l = -1, r = -1, n = intervals.size();
        for(int i = 0; i < n; i++) {
            int nl = intervals[i][0], nr = intervals[i][1];
            if(nl > r) {
                if(l != -1) res.push_back({l, r});
                l = nl;
                r = nr;
            } else if(nr > r) {
                r = nr;
            }
        }
        res.push_back({l, r});
        return res;
    }
};