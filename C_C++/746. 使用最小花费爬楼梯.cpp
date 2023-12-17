class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> f(n + 1);
        for(int i = 2; i <= n; i++) {
            f[i] = min(f[i - 1] + cost[i - 1], f[i - 2] + cost[i - 2]);
        }
        return f[n];
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int pre = 0;
        int cur = 0;

        for(int i = 0; i < cost.size(); i++)
        {
            int temp = cur;
            cur = min(cur, pre) + cost[i];
            pre = temp;
        }
        return min(cur, pre);
    }
};