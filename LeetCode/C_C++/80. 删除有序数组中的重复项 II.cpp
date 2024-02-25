class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = 0;
        for(auto num : nums)
        {
            if(res < 2 || num > nums[res-2])
            {
                nums[res++] = num;
            }
        }
        return res;
    }
};