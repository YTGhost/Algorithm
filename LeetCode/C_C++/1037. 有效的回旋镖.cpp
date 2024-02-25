class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int x1 = points[1][0] - points[0][0];
        int y1 = points[1][1] - points[0][1];
        int x2 = points[2][0] - points[0][0];
        int y2 = points[2][1] - points[0][1];
        return y1 * x2 != y2 * x1;
    }
};

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& p) {
        return (p[0][0] * (p[1][1] - p[2][1]) + p[1][0] * (p[2][1] - p[0][1]) + p[2][0] * (p[0][1] - p[1][1])) != 0;
    }
};