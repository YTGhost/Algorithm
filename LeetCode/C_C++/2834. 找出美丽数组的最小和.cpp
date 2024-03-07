class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        long long t = min(target / 2, n), mod = 1e9 + 7;
        return (t * (t + 1) + (n - t - 1 + 2 * target) * (n - t)) / 2 % mod;
    }
};