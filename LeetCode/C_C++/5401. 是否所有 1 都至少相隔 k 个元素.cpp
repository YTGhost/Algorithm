class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int count = 0;
        int sign = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1 && sign == 0) sign = 1;
            else if(nums[i] == 0 && sign == 1) count++;
            else if(nums[i] == 0 && sign == 0) continue;
            else{
                if(count < k) return false;
                count = 0;
            }
        }
        return true;
    }
};