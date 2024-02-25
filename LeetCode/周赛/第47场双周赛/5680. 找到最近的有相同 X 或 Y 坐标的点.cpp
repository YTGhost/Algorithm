class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int res = INT_MAX;
        int dis = INT_MAX;
        int n = points.size();
        for(int i = 0; i < n; i++)
        {
            if(points[i][0] == x && points[i][1] == y) {
                res = i;
                return res;
            } else if(points[i][0] == x) {
                int t = abs(y - points[i][1]);
                if(t < dis) {
                    dis = t;
                    res = i;
                }
            } else if(points[i][1] == y) {
                int t = abs(x - points[i][0]);
                if(t < dis) {
                    dis = t;
                    res = i;
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};