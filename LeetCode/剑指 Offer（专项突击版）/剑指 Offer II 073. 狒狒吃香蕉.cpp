class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = pow(10, 9);
        while(l < r) {
            int mid = l + r >> 1;
            if(check(piles, h, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
    bool check(vector<int>& piles, int h, int k) {
        int t = 0;
        for(int pile : piles) {
            t += (pile - 1) / k + 1;
        }
        return t <= h;
    }
};