class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), pre = 0, res = 0;
        unordered_map<int, int> hash;
        hash[0] = -1;
        for(int i = 0; i < n; i++) {
            pre += nums[i] == 0 ? -1 : 1;
            if(hash.count(pre)) {
                res = max(res, i - hash[pre]);
            } else {
                hash[pre] = i;
            }
        }
        return res;
    }
};