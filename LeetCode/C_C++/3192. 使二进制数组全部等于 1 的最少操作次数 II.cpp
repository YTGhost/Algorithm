class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (auto num : nums) {
            if (num == res % 2) {
                res++;
            }
        }
        return res;
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int l = 0, res = 0;
        while (l < n) {
            while(l < n && nums[l] == 1) {
                l++;
            }
            if (l >= n) {
                break;
            }
            int start = l;
            while(start < n && nums[start] == 0) {
                start++;
            }
            if (start == n) {
                res++;
                break;
            }
            int end = start;
            while (end < n && nums[end] == 1) {
                end++;
            }
            res += 2;
            l = end;
        }
        return res;
    }
};