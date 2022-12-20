class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        int res = 0;
        while(l <= r) {
            int mid = l + r >> 1;
            long long sum = 0;
            for(auto num : nums) {
                sum += (num - 1) / mid;
            }
            if(sum <= maxOperations) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};