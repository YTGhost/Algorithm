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