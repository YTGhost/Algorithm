class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(i > k) m[nums[i - k - 1]]--;
            if(m[nums[i]]) return true;
            m[nums[i]]++;
        }
        return false;
    }
};