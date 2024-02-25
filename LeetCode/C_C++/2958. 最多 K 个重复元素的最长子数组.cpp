class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int n = nums.size();
        int l = 0, res = 0;
        for(int r = 0; r < n; r++) {
            hash[nums[r]]++;
            while(hash[nums[r]] > k) {
                hash[nums[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};