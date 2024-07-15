class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        unordered_set<int> st1;
        unordered_set<int> st2;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            st1.insert(nums1[i]);
        }
        for (int i = 0; i < m; i++) {
            st2.insert(nums2[i]);
            if (st1.contains(nums2[i])) {
                cnt2++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (st2.contains(nums1[i])) {
                cnt1++;
            }
        }
        return vector<int>{cnt1, cnt2};
    }
};