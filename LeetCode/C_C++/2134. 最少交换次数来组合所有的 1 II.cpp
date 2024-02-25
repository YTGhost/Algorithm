class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) cnt++;
        }
        int sum = 0;
        for(int i = 0; i < cnt; i++) {
            if(nums[i] == 0) sum++;
        }
        int res = sum;
        for(int i = 1; i < n; i++) {
            if(nums[i - 1] == 0) sum--;
            if(nums[(i + cnt - 1) % n] == 0) sum++;
            res = min(res, sum);
        }
        return res;
    }
};