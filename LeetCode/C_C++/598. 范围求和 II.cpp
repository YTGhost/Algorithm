class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minm = m, minn = n;
        for(auto op : ops) {
            minm = min(minm, op[0]);
            minn = min(minn, op[1]);
        }
        return minm * minn;
    }
};