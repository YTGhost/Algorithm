class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp(nums.begin(), nums.end());
        sort(temp.begin(), temp.end());
        int l = 0, r = nums.size()-1;
        while(l <= r && nums[l] == temp[l]) l++;
        while(l <= r && nums[r] == temp[r]) r--;
        return r - l + 1;
    }
};