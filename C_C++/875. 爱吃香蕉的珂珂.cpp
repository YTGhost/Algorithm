class Solution {
public:
    bool check(vector<int>& piles, int t, int h) {
        int sum = 0;
        for(auto pile : piles) {
            sum += pile / t;
            if(pile % t > 0) {
                sum++;
            }
        }
        return sum <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1, end = *max_element(piles.begin(), piles.end()) + 1;
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(check(piles, mid, h)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};

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