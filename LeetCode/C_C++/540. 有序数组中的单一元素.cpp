class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n / 2;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid * 2] != nums[mid * 2 + 1]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[2 * l];
    }
};

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int l = 0, r = n;
        int res;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (mid == 0 && nums[mid] != nums[mid + 1]) {
                res = nums[mid];
                break;
            }
            if (mid == n - 1 && nums[mid] != nums[mid - 1]) {
                res = nums[mid];
                break;
            }
            if (mid != 0 && mid != n - 1 && nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                res = nums[mid];
                break;
            }
            if (mid && nums[mid] == nums[mid - 1]) {
                if (mid % 2 == 0) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (mid != n - 1 && nums[mid] == nums[mid + 1]) {
                if (mid % 2 == 0) {
                    l = mid + 2;
                } else {
                    r = mid;
                }
            }
        }
        return res;
    }
};

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