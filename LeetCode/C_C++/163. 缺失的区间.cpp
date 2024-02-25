class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        nums.insert(nums.begin(), lower - 1);
        nums.push_back(upper+1);
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            int diff = nums[i] - nums[i - 1];
            if(diff == 1 || diff == 0) {
                continue;
            } else if (diff == 2) {
                res.push_back(to_string(nums[i] - 1));
            } else {
                res.push_back(to_string(nums[i - 1] + 1) + "->" + to_string(nums[i] - 1));
            }
        }
        return res;
    }
};