class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxLen = 0, res = 0;
        for(auto rectangle : rectangles) {
            int cur = min(rectangle[0], rectangle[1]);
            if(cur == maxLen) res++;
            else if(cur >= maxLen) {
                maxLen = cur;
                res = 1;
            }
        }
        return res;
    }
};