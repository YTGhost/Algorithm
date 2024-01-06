class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n - 1;
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] < nums[n - 1]) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return nums[end];
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(nums[mid] < nums[r]) r = mid;
            else l = mid + 1;
        }
        return nums[l];
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(nums[mid] > nums[r]) l = mid + 1;
            else if(nums[mid] < nums[r]) r = mid; 
        }
        return nums[l];
    }
};