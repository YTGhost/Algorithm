class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lower_bound(nums, target);
        if(start == nums.size() || nums[start] != target) {
            return {-1, -1};
        }
        int end = lower_bound(nums, target + 1) - 1;
        return {start, end};
    }
};

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