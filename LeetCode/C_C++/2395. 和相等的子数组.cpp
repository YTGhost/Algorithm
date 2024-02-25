class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            int sum = nums[i] + nums[i + 1];
            if(s.count(nums[i] + nums[i + 1])) {
                return true;
            } else {
                s.insert(sum);
            }
        }
        return false;
    }
};