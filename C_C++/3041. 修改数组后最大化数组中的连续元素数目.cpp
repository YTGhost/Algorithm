class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> f(1e6 + 2, 0);
        for(int i = n - 1; i >= 0; i--) {
            f[nums[i]] = f[nums[i] + 1] + 1;
            f[nums[i] + 1] = f[nums[i] + 2] + 1;
        }
        int res = 0;
        for(auto num : f) {
            res = max(res, num);
        }
        return res;
    }
};