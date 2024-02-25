class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(!nums.size()) return 0;
        int l = 0, r = nums.size()-1;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(nums[mid] < target) l = mid + 1;
            else r = mid;
        }
        int left = l;
        if(nums[l] != target) return 0;
        
        l = 0, r = nums.size()-1;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if(nums[mid] <= target) l = mid;
            else r = mid-1;
        }
        int right = l;
        return right-left+1;
    }
};