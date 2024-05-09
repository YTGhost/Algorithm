class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size();
        int l = 0, r = n - 1;
        int curA = capacityA, curB = capacityB;
        int res = 0;
        while(l <= r) {
            if(l == r) {
                if(curA >= curB) {
                    if(curA < plants[l]) {
                        curA = capacityA;
                        res++;
                    }
                    curA -= plants[l];
                } else if(curA < curB) {
                    if(curB < plants[r]) {
                        curB = capacityB;
                        res++;
                    }
                    curB -= plants[r];
                }
            } else {
                if(curA < plants[l]) {
                    curA = capacityA;
                    res++;
                }
                if(curB < plants[r]) {
                    curB = capacityB;
                    res++;
                }
                curA -= plants[l];
                curB -= plants[r];
            }
            l++;
            r--;
        }
        return res;
    }
};