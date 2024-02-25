class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if(size == 0 || size == 1) return 0;
        sort(intervals.begin(), intervals.end(), [](const auto & a, const auto & b) {
            return a[0] < b[0];
        });
        vector<int> f(size, 1);
        for(int i = 1; i < size; i++)
            for(int j = 0; j < i; j++)
            {
                if(intervals[j][1] <= intervals[i][0]) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        return size - *max_element(f.begin(), f.end());
    }
};