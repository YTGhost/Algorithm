class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int res = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            res = max(res, sum);
            if(sum < 0) sum = 0;
        }
        return res;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, res = INT_MIN;
        for(auto num : nums)
        {
            if(sum < 0) sum = 0;
            sum += num;
            res = max(res, sum);
        }
        return res;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, sum = 0, l = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            ans = sum > ans ? sum : ans;
            if(sum < 0) sum = 0;
        }
        return ans;
    }
};