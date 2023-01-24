class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        for(auto num : nums) {
            if(num == original) {
                original *= 2;
            }
        }
        return original;
    }
};