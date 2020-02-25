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