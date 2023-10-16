class Solution {
public:
    int indexDifference;
    int valueDifference;
    bool check(int i, int j, vector<int>& nums) {
        if(abs(i - j) >= indexDifference && abs(nums[i] - nums[j]) >= valueDifference) {
            return true;
        }
        return false;
    }
    vector<int> findIndices(vector<int>& nums, int _indexDifference, int _valueDifference) {
        int n = nums.size();
        indexDifference = _indexDifference;
        valueDifference = _valueDifference;
        vector<int> res = {-1, -1};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(check(i, j, nums)) {
                    res[0] = i, res[1] = j;
                    return res;
                }
            }
        }
        return res;
    }
};