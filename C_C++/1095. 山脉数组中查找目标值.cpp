/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l = 0, r = mountainArr.length() - 1;
        int peek, index1, index2, ans;

        while(l < r)
        {
            int mid = l + r >> 1;
            if(mountainArr.get(mid) < mountainArr.get(mid + 1)) l = mid + 1;
            else r = mid;
        }
        peek = l;

        l = 0, r = peek;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(mountainArr.get(mid) >= target) r = mid;
            else l = mid + 1;
        }
        index1 = mountainArr.get(l) == target ? l : -1;

        l = peek, r = mountainArr.length() - 1;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(mountainArr.get(mid) > target) l = mid + 1;
            else r = mid;
        }
        index2 = mountainArr.get(l) == target ? l : -1;

        if(index1 != -1 && index2 != -1) ans = min(index1, index2);
        else if(index1 == -1 && index2 != -1) ans = index2;
        else if(index1 != -1 && index2 == -1) ans = index1;
        else ans = -1;
        return ans;
    }
};