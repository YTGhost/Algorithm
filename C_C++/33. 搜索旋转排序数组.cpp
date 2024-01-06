class Solution {
public:
    bool isBlue(vector<int>& nums, int i, int target) {
        int end = nums[nums.size() - 1];
        if(nums[i] > end) {
            return target > end && nums[i] >= target;
        } else {
            return target > end || nums[i] >= target;
        }
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0, end = n - 1;
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(isBlue(nums, mid, target)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        if(nums[start] != target) {
            return -1;
        }
        return start;
    }
};

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
        return end;
    }
    int lower_bound(vector<int>& nums, int l, int r, int target) {
        int t = r;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l < t && nums[l] == target ? l : -1;
    }
    int search(vector<int>& nums, int target) {
        int i = findMin(nums);
        int n = nums.size();
        int l, r;
        if(target > nums[n - 1]) {
            l = 0, r = i;
        } else {
            l = i, r = n;
        }
        return lower_bound(nums, l, r, target);
    }
};

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