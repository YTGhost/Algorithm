class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int cur = 0, pre = 0; cur < nums.size(); i++)
        {
            while(cur < nums.size() && nums[cur] == nums[pre]) cur++;
            nums[i] = nums[pre];
            pre = cur;
        }
        return i;
    }
};