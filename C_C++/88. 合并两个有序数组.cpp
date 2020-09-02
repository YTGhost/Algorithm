class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> t(m+n, 0);
        int p = 0, q = 0, k = 0;
        while(p < m && q < n)
        {
            if(nums1[p] <= nums2[q]) t[k++] = nums1[p++];
            else t[k++] = nums2[q++];
        }
        while(p < m) t[k++] = nums1[p++];
        while(q < n) t[k++] = nums2[q++];
        for(int i = 0; i < m+n; i++) nums1[i] = t[i];
    }
};
