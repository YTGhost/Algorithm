class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(!nums.size()) return {-1, -1};
        int l = 0, r = nums.size()-1;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(nums[mid] < target) l = mid+1;
            else r = mid;
        }
        int left = l;
        if(nums[l] != target) return {-1, -1};

        l = 0, r = nums.size()-1;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if(nums[mid] > target) r = mid-1;
            else l = mid;
        }
        return {left, l};
    }
};