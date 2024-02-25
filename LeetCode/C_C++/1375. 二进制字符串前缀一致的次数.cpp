class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int res = 0, num = 0, n = flips.size();
        for(int i = 0; i < n; i++) {
            num = max(num, flips[i]);
            if(num == i + 1) {
                res++;
            }
        }
        return res;
    }
};