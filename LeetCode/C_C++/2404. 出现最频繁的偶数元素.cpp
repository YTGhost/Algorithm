class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto num : nums) {
            if(num % 2 == 0) {
                m[num]++;
            }
        }
        int res = -1, maxCnt = 0;
        for(auto &[key, value] : m) {
            if(value > maxCnt) {
                maxCnt = value;
                res = key;
            } else if(value == maxCnt) {
                res = min(res, key);
            }
        }
        return res;
    }
};