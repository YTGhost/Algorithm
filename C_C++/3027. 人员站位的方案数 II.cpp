class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        ranges::sort(points, [&](const auto &a, const auto &b) {
            if(a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });
        int n = points.size(), res = 0;
        for(int i = 0; i < n; i++) {
            int p1 = points[i][1];
            int maxVal = INT_MIN;
            for(int j = i + 1; j < n; j++) {
                int p2 = points[j][1];
                if(p2 <= p1 && p2 > maxVal) {
                    maxVal = p2;
                    res++;
                }
            }
        }
        return res;
    }
};