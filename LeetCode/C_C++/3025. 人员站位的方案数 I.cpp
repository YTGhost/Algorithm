class Solution {
public:
    int check(int a, int b, vector<vector<int>>& points) {
        int n = points.size();
        auto p1 = points[a], p2 = points[b];
        if(p1[0] > p2[0] || p1[1] < p2[1]) return 0;
        for(int i = 0; i < n; i++) {
            if(i == a || i == b) continue;
            auto p3 = points[i];
            if(p3[0] <= p2[0] && p3[0] >= p1[0] && p3[1] >= p2[1] && p3[1] <= p1[1]) return 0;
        }
        return 1;
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size(), res = 0;
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                res += check(i, j, points) + check(j, i, points);
            }
        }
        return res;
    }
};