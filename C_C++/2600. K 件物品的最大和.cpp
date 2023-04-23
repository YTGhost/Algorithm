class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int res = 0;
        if(k <= numOnes) return k;
        k -= numOnes;
        res += numOnes;
        if(k <= numZeros) return res;
        k -= numZeros;
        return res - k;
    }
};