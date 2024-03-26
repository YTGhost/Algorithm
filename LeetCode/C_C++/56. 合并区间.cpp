class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int l = intervals[0][0], r = intervals[0][1];
        for(int i = 1; i < n; i++) {
            if (intervals[i][0] <= r) {
                r = max(r, intervals[i][1]);
            } else {
                res.push_back(vector<int>{l, r});
                l = intervals[i][0], r = intervals[i][1];
            }
        }
        res.push_back(vector<int>{l, r});
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for(int i = 0; i < intervals.size(); i++) {
            int l = intervals[i][0], r = intervals[i][1];
            if(!res.size() || res.back()[1] < l) {
                res.push_back({l, r});
            } else {
                res.back()[1] = max(res.back()[1], r);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1 || intervals.size() == 0) return intervals;
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++)
        {
            if(ans.back()[1] >= intervals[i][0])
            {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};