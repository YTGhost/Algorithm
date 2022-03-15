class Solution {
public:
    int f[1005];
    int minCostClimbingStairs(vector<int>& cost) {
        int res = 0, n = cost.size();
        for(int i = 2; i <= n; i++) {
            f[i] = min(f[i - 2] + cost[i - 2], f[i - 1] + cost[i - 1]);
        }
        return f[n];
    }
};