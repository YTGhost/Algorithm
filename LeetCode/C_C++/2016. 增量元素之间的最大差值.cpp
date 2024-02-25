class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minNum = 1e9 + 5;
        int res = -1;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(i && nums[i] > minNum) res = max(res, nums[i] - minNum);
            minNum = min(minNum, nums[i]);
        }
        return res;
    }
};