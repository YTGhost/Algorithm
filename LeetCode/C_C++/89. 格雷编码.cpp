class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        while(n-- > 0) {
            int m = res.size();
            for(int i = m - 1; i >= 0; i--) {
                res[i] = res[i] << 1;
                res.push_back(res[i] + 1);
            }
        }
        return res;
    }
};