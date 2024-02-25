class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, n = nums.size();
        while(l < r) {
            int mid = l + r >> 1;
            if(mid % 2 == 0) {
                if(mid + 1 < n && nums[mid] == nums[mid + 1]) l = mid + 1;
                else r = mid;
            } else {
                if(mid - 1 >= 0 && nums[mid] == nums[mid - 1]) l = mid + 1;
                else r = mid;
            }
            
        }
        return nums[l];
    }
};