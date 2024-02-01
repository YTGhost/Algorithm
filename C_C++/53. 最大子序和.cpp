class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0, res = INT_MIN, sum = 0;
        while(r < n) {
            sum += nums[r];
            res = max(res, sum);
            while(sum < 0) {
                sum -= nums[l++];
            }
            r++;
        }
        return res;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, sum = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            res = max(res, sum);
            if(sum < 0) {
                sum = 0;
            }
        }
        return res;
    }
};

// AcWing打卡重做
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            maxSum = max(maxSum, sum);
            if(sum < 0) sum = 0;
            sum += nums[i];
        }
        return max(maxSum, sum);
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        int temp = 0;
        for(auto i : nums)
        {
            if(temp > 0)
            {
                temp += i;
            }else
            {
                temp = i;
            }
            max = std::max(max, temp);
        }
        return max;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, ans = nums[0];
        for(int item : nums)
        {
            if(sum >= 0) sum += item;
            else sum = item;
            ans = max(ans, sum);
        }
        return ans;
    }
};