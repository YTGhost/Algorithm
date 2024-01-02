class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0, n = nums.size(), res = 0, cnt = 0;
        for(int r = 0; r < n; r++) {
            if(nums[r] == 0) {
                cnt++;
            }
            while(cnt > 1) {
                if(nums[l] == 0) {
                    cnt--;
                }
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};