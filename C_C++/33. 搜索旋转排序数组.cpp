class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int min = findMin(nums);
        int l = 0, r = nums.size() - 1;
        
        if(min != 0){   // 可能旋转也可能不旋转
            if(target < nums[0]) l = min;
            else r = min - 1;
        }
        
        while(l < r)
        {
            int mid = l + r >> 1;
            if(nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return nums[l] == target ? l : -1;
    }

    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(nums[mid] > nums[r]) l = mid + 1;
            else if(nums[mid] < nums[r]) r = mid; 
        }
        return l;
    }
};