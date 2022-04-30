class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int maxVal = nums[0], minVal = nums[0];
        for(auto num : nums) {
            maxVal = max(maxVal, num);
            minVal = min(minVal, num);
        }
        return max(0, maxVal - minVal - 2 * k);
    }
};

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return 0;
        int minV, maxV;
        minV = min(nums[0], nums[1]);
        maxV = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++) {
            minV = min(nums[i], minV);
            maxV = max(nums[i], maxV);
        }
        if(maxV - minV <= 2 * k) return 0;
        else return maxV - minV - 2 * k;
    }
};