class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        res[0] = 1;
        for(int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        int r = 1;
        for(int i = n - 1; i >= 0; i--) {
            res[i] = res[i] * r;
            r = r * nums[i];
        }
        return res;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        ans[0] = 1;
        for(int i = 1; i < nums.size(); i++) ans[i] = nums[i-1] * ans[i-1];

        int rSum = 1;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            ans[i] = rSum * ans[i];
            rSum *= nums[i];
        }
        return ans;
    }
};