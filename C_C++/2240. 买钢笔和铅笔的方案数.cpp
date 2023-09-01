class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long res = 0;
        int maxCnt1 = total / cost1;
        for(int i = 0; i <= maxCnt1; i++) {
            int t = total - cost1 * i;
            res += t / cost2 + 1;
        }
        return res;
    }
};