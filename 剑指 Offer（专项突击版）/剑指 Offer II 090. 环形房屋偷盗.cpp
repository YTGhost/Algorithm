class Solution {
public:
    int f[105];
    int toSolve(vector<int>& nums, int l, int r) {
        int first = nums[l], second = max(nums[l], nums[l + 1]);
        for(int i = l + 2; i <= r; i++) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        else if(n == 2) return max(nums[0], nums[1]);
        return max(toSolve(nums, 1, nums.size() - 1), toSolve(nums, 0, nums.size() - 2));
    }
};