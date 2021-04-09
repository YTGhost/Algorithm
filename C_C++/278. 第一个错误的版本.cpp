// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long l = 1, r = n;
        while(l < r)
        {
            long mid = l + r >> 1;
            if(!isBadVersion(mid)) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};