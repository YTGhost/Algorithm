class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int minVal1 = INT_MAX, minVal2 = INT_MAX;
        for (int i = 0; i < n; i++) {
            minVal1 = min(minVal1, nums1[i]);
            minVal2 = min(minVal2, nums2[i]);
        }
        return minVal2 - minVal1;
    }
};