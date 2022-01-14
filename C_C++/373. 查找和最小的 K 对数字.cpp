class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        int n = nums1.size(), m = nums2.size();
        auto cmp = [&](const auto& a, const auto& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for(int i = 0; i < min((int)nums1.size(), k); i++) {
            q.push({i, 0});
        }
        while(res.size() < k && q.size()) {
            auto [a, b] = q.top();
            q.pop();
            res.push_back({nums1[a], nums2[b]});
            if(b + 1 < m) q.push({a, b + 1});
        }
        return res;
    }
};