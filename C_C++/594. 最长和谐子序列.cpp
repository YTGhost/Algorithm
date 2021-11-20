class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            int j = i + 1;
            while(j < n && nums[j] - nums[i] <= 1) {
                if(nums[j] - nums[i] == 1) res = max(res, j - i + 1);
                j++;
            }
        }
        return res;
    }
};