class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int n = nums.size(), sum = 1, res = 0;
        int left = 0;
        for(int right = 0; right < n; right++) {
            sum *= nums[right];
            while(sum >= k) {
                sum /= nums[left];
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
};

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0) return 0;
        int n = nums.size(), l = 0, r = 0, sum = 1, res = 0;
        while(r < n) {
            sum *= nums[r];
            while(l <= r && sum >= k) {
                sum /= nums[l++];
            }
            res += r - l + 1;
            r++;
        }
        return res;
    }
};