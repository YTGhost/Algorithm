/**
 * test
 */
public class test {

    public static void main(String[] args) {
        int[] nums1 = new int[]{1,3,4,7};
        int[] nums2 = new int[]{1,2,3,4,5,6,7,8,9,10};
        int length = nums1.length + nums2.length;
        int i = 0;
        int j = 0;
        int k = 0;
        double ans = 0;
        k = length / 2;
        while(k!=0){
            if(nums1[i + k / 2 -1]>nums2[j + k / 2 -1]){
                j += k / 2;
                k -= j;
            }else{
                i += k / 2;
                k -= i;
            }
            // k /= 2;
        }
        if(length % 2 == 0){
            ans = (nums1[i] + nums2[j]) / 2.0;
        }else{
            if(nums1[i] < nums2[j]){
                System.out.println(i);
                ans = nums1[i];
            }else{
                System.out.println(j);
                ans = nums2[j];
            }
        }
        System.out.println(ans);
    }
}