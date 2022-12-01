class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int n = points.size();
        int dis = INT_MAX;
        int res = -1;
        for(int i = n - 1; i >= 0; i--) {
            if(points[i][0] == x || points[i][1] == y) {
                int t = abs(points[i][0] - x) + abs(points[i][1] - y);
                if (t <= dis) {
                    dis = t;
                    res = i;
                }
            }
        }
        return res;
    }
};