

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int left = newInterval[0], right = newInterval[1], n = intervals.size();
        bool flag = false;
        for(const auto &interval : intervals) {

            if(interval[0] > right) {
                if(!flag) {class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int l = newInterval[0], r = newInterval[1];
        bool flag = false;
        for(const auto &interval : intervals) {
            if(interval[1] < l) {
                res.push_back(interval);
            } else if(interval[0] > r) {
                if(!flag) {
                    res.push_back({l, r});
                    flag = true;
                }
                res.push_back(interval);
            } else {
                l = min(l, interval[0]);
                r = max(r, interval[1]);
            }
        }
        if(!flag) {
            res.push_back({l, r});
        }
        return res;
    }
};
                    res.push_back({left, right});
                    flag = true;
                }
                res.push_back(interval);
            } else if(interval[1] < left) {
                res.push_back(interval);
            } else {
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if(!flag) {
            res.push_back({left, right});
        }
        return res;
    }
};