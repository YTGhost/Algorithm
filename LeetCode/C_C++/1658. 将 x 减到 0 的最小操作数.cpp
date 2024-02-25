class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < x) {
            return -1;
        }
        int right = 0, leftsum = 0, rightsum = sum, res = n + 1;
        for(int left = -1; left < n; left++) {
            if(left != -1) {
                leftsum += nums[left];
            }
            while(right < n && leftsum + rightsum > x) {
                rightsum -= nums[right];
                right++;
            }
            if(leftsum + rightsum == x) {
                res = min(res, left + 1 + n - right);
            }
        }
        return res > n ? -1 : res;
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, n = nums.size();
        for(int i = 0; i < n; i++) sum += nums[i];
        sum -= x;
        if(sum < 0) return -1;
        // 转换成求和等于sum的最长连续子数组
        int l = 0, r = 0, res = -1, temp = 0;
        while(r < n)
        {
            temp += nums[r];
            while(temp > sum) temp -= nums[l++];
            if(temp == sum) res = max(res, r - l + 1);
            r++;
        }
        return res == -1 ? -1 : n - res;
    }
};