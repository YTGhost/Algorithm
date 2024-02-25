class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int res = 0;
        int maxCnt = 0;
        unordered_map<int, int> m;
        for(auto num : nums) {
            m[num]++;
        }
        for(auto &[k, v] : m) {
            if(v > maxCnt) {
                maxCnt = v;
                res = v;
            } else if(v == maxCnt) {
                res += v;
            }
        }
        return res;
    }
};