/**
 * 4. 寻找两个有序数组的中位数（时间复杂度log(m+n)）
 */
public class 4. 寻找两个有序数组的中位数（时间复杂度log(m+n)） {

    public static void main(String[] args) {
        int length = nums1.length + nums2.length;
        int i = 0;
        int j = 0;
        int k = 0;
        double ans = 0;
        k = length / 2;
        while(k!=0){
            if(nums1[k / 2 -1]>nums2[k / 2 -1]){
                j = k;
                k -= j-1;
            }else{
                i = k;
                k -= i-1;
            }
            k /= 2;
        }
        if(length % 2 == 0){
            ans = (nums1[i] + nums2[j]) / 2.0;
        }else{
            if(nums1[i] < nums2[j]){
                ans = nums1[i];
            }else{
                ans = nums2[j];
            }
        }
        return ans;
    }
}