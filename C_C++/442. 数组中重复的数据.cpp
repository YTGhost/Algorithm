class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i = 0; i < n; i++) {
            int t = nums[i];
            if(t < 0 || t - 1 == i) continue;
            if(nums[t - 1] == t) {
                res.push_back(t);
                nums[i] = -1;
            } else {
                swap(nums[i--], nums[t - 1]);
            }
        }
        return res;
    }
};