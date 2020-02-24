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