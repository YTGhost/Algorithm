class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        function<int(int)> lower_bound = [&](int target) {
            int l = 0, r = nums.size();
            while(l < r) {
                int mid = l + (r - l) / 2;
                if (nums[mid] >= target) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            return l;
        };
        return lower_bound(target);
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        function<int(int)> lower_bound = [&](int target) {
            int l = 0, r = nums.size();
            while(l < r) {
                int mid = l + (r - l) / 2;
                if (nums[mid] >= target) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            return l;
        };
        int idx = lower_bound(target + 1) - 1;
        if(idx == -1) return 0;
        if(nums[idx] == target) return idx;
        return idx + 1;
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        function<int(int)> lower_bound = [&](int target) {
            int l = 0, r = nums.size();
            while(l < r) {
                int mid = l + (r - l) / 2;
                if (nums[mid] >= target) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            return l;
        };
        int idx = lower_bound(target);
        if(idx == nums.size()) {
            return lower_bound(target + 1);
        }
        return idx;
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        for(int i = 0; i < size; i++)
        {
            if(nums[i] >= target) return i;
        }
        return size;
    }
};