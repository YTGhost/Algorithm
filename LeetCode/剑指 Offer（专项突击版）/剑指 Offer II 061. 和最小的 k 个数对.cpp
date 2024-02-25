class Solution {
public:
    typedef pair<int, int> PII;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        bool flag = false;
        if(m < n) {
            flag = true;
            swap(n, m);
            swap(nums1, nums2);
        }
        auto cmp = [&](const PII& a, const PII& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<PII, vector<PII>, decltype(cmp)> q(cmp);
        for(int i = 0; i < min(n, k); i++) {
            q.push({i, 0});
        }
        vector<vector<int>> res;
        while(res.size() < k && q.size()) {
            auto [a, b] = q.top();
            q.pop();
            flag ? res.push_back({nums2[b], nums1[a]}) : res.push_back({nums1[a], nums2[b]});
            if(b + 1 < m) q.push({a, b + 1});
        }
        return res;
    }
};