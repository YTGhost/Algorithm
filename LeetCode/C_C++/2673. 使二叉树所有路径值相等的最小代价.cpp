class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int res = 0;
        for(int i = n / 2; i > 0; i--) {
            res += abs(cost[i * 2 - 1]- cost[i * 2]);
            cost[i - 1] += max(cost[i * 2 - 1], cost[i * 2]);
        }
        return res;
    }
};