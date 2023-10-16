class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int maxIdx = 0, minIdx = 0;
        int n = nums.size();
        for(int j = indexDifference; j < n; j++) {
            int i = j - indexDifference;
            if(nums[i] > nums[maxIdx]) {
                maxIdx = i;
            } else if(nums[i] < nums[minIdx]) {
                minIdx = i;
            }
            if(nums[maxIdx] - nums[j] >= valueDifference) {
                return {maxIdx, j};
            } else if(nums[j] - nums[minIdx] >= valueDifference) {
                return {minIdx, j};
            }
        }
        return {-1, -1};
    }
};