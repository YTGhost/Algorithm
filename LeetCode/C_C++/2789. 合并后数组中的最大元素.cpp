class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long sum = nums.back();
        for(int i = nums.size() - 2; i >= 0; i--) {
            sum = nums[i] <= sum ? sum + nums[i] : nums[i];
        }
        return sum;
    }
};