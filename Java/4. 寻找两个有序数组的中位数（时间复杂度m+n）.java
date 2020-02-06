class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int i = 0;
        int j = 0;
        int k = 0;
        int length = nums1.length + nums2.length;
        double ans = 0;
        int [] nums = new int [nums1.length + nums2.length];
        while(i < nums1.length && j < nums2.length){
            if(nums1[i] < nums2[j]){
                nums[k++] = nums1[i++];
            }else{
                nums[k++] = nums2[j++];
            }
        }
        while(i < nums1.length){
            nums[k++] = nums1[i++];
        }
        while(j < nums2.length){
            nums[k++] = nums2[j++];
        }
        if(length % 2 == 0){
            ans = (nums[length / 2 - 1] + nums[length / 2]) / 2.0;
        }else{
            ans = nums[length / 2];
        }
        return ans;
    }
}