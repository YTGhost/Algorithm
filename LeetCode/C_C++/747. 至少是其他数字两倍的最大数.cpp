class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int first = 0, second = 0, index;
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0) {
                first = nums[i];
                index = i;
            } else {
                if(nums[i] > first) {
                    second = first;
                    first = nums[i];
                    index = i;
                } else if(nums[i] > second) {
                    second = nums[i];
                }
            }
        }
        return first >= second * 2 ? index : -1;
    }
};