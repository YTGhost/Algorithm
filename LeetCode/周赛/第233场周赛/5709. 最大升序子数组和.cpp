class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size(), sum = 0, pre = 0, res = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > pre) {
                sum += nums[i];
                pre = nums[i];
                res = max(res, sum);
            } else {
                pre = nums[i];
                sum = nums[i];
            }
        }
        return res;
    }
};