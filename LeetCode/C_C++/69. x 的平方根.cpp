class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        long r = x;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if((long)mid * mid > x) r = mid - 1;
            else l = mid;
        }
        return l;
    }
};