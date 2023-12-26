class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1, p3 = m + n - 1;
        while(p2 >= 0) {
            if(p1 < 0 || nums2[p2] >= nums1[p1]) {
                nums1[p3--] = nums2[p2--]; 
            } else {
                nums1[p3--] = nums1[p1--];
            }
        }
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1;
        int tail = m + n - 1;
        int cur;
        while (p1 >= 0 || p2 >= 0)
        {
            if (p1 == -1) {
                cur = nums2[p2--];
            } else if (p2 == -1) {
                cur = nums1[p1--];
            } else if (nums1[p1] > nums2[p2]) {
                cur = nums1[p1--];
            } else {
                cur = nums2[p2--];
            }
            nums1[tail--] = cur;
        }
    }
};

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
