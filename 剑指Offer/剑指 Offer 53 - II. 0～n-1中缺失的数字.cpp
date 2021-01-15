class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        if(r == 0) return nums[0] ? 0 : 1; 
        while(l < r)
        {
            int mid = l + r >> 1;
            if(nums[mid] != mid) r = mid;
            else l = mid + 1;
        }
        if(nums[r] == r) r++;
        return r;
    }
};