class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        while(numBottles >= numExchange) {
            int t = numBottles % numExchange;
            numBottles /= numExchange;
            res += numBottles;
            numBottles += t;
        }
        return res;
    }
};