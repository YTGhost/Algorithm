class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int t = purchaseAmount % 10;
        if (t >= 5) {
            return 100 - (purchaseAmount + 10 - t);
        }
        return 100 - (purchaseAmount - t);
    }
};