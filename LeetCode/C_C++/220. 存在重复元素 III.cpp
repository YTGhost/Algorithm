class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        set<int> s;
        for(int i = 0; i < n; i++) {
            auto item = s.lower_bound(max(nums[i], INT_MIN + t) - t);
            if(item != s.end() && *item <= min(nums[i], INT_MAX - t) + t) {
                return true;
            }
            s.insert(nums[i]);
            if(i >= k) {
                s.erase(nums[i - k]);
            }
        }
        return false;
    }
};