class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int res = 0;
        double maxLong = 0;
        int n = dimensions.size();
        for(int i = 0; i < n; i++) {
            int a = dimensions[i][0], b = dimensions[i][1];
            double length = sqrt(a * a + b * b);
            if(length >= maxLong) {
                if(length > maxLong) {
                    maxLong = length;
                    res = a * b;
                } else if(length == maxLong) {
                    res = max(res, a * b);
                }
            }
        }
        return res;
    }
};