class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> suf(n + 1);
        unordered_set<int> s;
        for(int i = n - 1; i >= 0; i--) {
            s.insert(nums[i]);
            suf[i] = s.size();
        }
        s.clear();
        vector<int> res(n);
        for(int i = 0; i < n; i++) {
            s.insert(nums[i]);
            res[i] = s.size() - suf[i + 1];
        }
        return res;
    }
};