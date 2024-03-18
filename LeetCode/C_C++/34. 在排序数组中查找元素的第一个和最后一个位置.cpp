class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        function<int(int)> lower_bound = [&](int target) {
            int l = 0, r = n;
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
        vector<int> res(2, -1);
        if(n == 0) return res;
        int idx1 = lower_bound(target);
        int idx2 = lower_bound(target + 1) - 1;
        res[0] = (idx1 != n && nums[idx1] == target) ? idx1 : -1;
        res[1] = (idx2 != -1 && nums[idx2] == target) ? idx2 : -1;
        return res;
    }
};

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