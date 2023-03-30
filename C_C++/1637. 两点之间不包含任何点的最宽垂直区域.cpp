class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int res = 0;
        for(int i = 0; i < n - 1; i++) {
            res = max(res, points[i+1][0] - points[i][0]);
        }
        return res;
    }
};