class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size(), res = -1;
        for(int i = 0; i < n - 1; i++) {
            int len = 1;
            bool flag = true;
            for(int j = i; j < n - 1; j++) {
                if(nums[j + 1] - nums[j] == (flag ? 1 : -1)) {
                    len++;
                    flag = !flag;
                    res = max(res, len);
                } else {
                    break;
                }
            }
        }
        return res;
    }
};