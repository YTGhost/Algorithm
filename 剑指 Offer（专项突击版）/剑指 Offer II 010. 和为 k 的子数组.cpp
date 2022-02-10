class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), pre = 0, res = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for(int i = 0; i < n; i++) {
            pre += nums[i];
            res += m[pre - k];
            m[pre]++;
        }
        return res;
    }
};