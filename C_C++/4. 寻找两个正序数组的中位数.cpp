// LeetCode究极班打卡
class Solution {
public:
    int find(vector<int>& nums1, int i, vector<int>& nums2, int j, int k){
        if(nums1.size() - i > nums2.size() - j) return find(nums2, j, nums1, i, k);
        if(nums1.size() == i) return nums2[j+k-1];
        if(k == 1) return min(nums1[i], nums2[j]);
        int si = min(i + k/2, (int)nums1.size()), sj = j + k/2;
        if(nums1[si-1] > nums2[sj-1]) return find(nums1, i, nums2, sj, k - (sj - j));
        else return find(nums1, si, nums2, j, k - (si - i));
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int count = nums1.size() + nums2.size();
        double ans;
        if(count % 2 == 0){
            int left = find(nums1, 0, nums2, 0, count/2);
            int right = find(nums1, 0, nums2, 0, count/2 + 1);
            ans = (left + right) / 2.0;
        }else{
            ans = find(nums1, 0, nums2, 0, count/2 + 1);
        }
        return ans;
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        }
        else {
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0, index2 = 0;
        while (true) {
            // 边界情况
            if (index1 == m) {
                return nums2[index2 + k - 1];
            }
            if (index2 == n) {
                return nums1[index1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[index1], nums2[index2]);
            }

            // 正常情况
            int newIndex1 = min(index1 + k / 2 - 1, m - 1);
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];
            if (pivot1 <= pivot2) {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }
            else {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }
};