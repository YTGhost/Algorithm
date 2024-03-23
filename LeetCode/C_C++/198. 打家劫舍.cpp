class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        nums[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++) {
            nums[i] = max(nums[i] + nums[i - 2], nums[i - 1]);
        }
        return nums[n - 1];
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        nums[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++) {
            nums[i] = max(nums[i] + nums[i - 2], nums[i - 1]);
        }
        return max(nums[n - 1], nums[n - 2]);
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int preMax = 0;
        int curMax = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int temp = curMax;
            curMax = max(preMax + nums[i], curMax);
            preMax = temp;
        }
        return curMax;
    }
};