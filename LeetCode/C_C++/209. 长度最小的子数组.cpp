class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), sum = 0, left = 0, res = n + 1;
        for(int right = 0; right < n; right++) {
            sum += nums[right];
            while(sum >= target) {
                res = min(res, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return res <= n ? res : 0;
    }
};

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0, end = 0, sum = 0;
        int size = nums.size();
        int ans = size+1;
        while(end != size)
        {
            sum += nums[end];
            while(sum >= s)
            {
                ans = min(ans, end-start+1);
                sum -= nums[start++];
            } 
            end++;
        }
        return ans == size+1 ? 0 : ans;
    }
};