class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = INT_MAX;
        vector<pair<int, int>> ors;
        for (int i = 0; i < nums.size(); i++) {
            ors.emplace_back(0, i);
            int j = 0;
            for (auto &p : ors) {
                auto &[or_, left] = p;
                or_ |= nums[i];
                if (or_ >= k) {
                    ans = min(ans, i - left + 1);
                }
                if (ors[j].first == or_) {
                    ors[j].second = left;
                } else {
                    ors[++j] = p;
                }
            }
            ors.resize(j + 1);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};