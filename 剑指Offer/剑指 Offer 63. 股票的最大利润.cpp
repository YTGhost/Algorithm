class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size()) return 0;
        int res = 0;
        for(int i = 0, minV = prices[0]; i < prices.size(); i++)
        {
            res = max(res, prices[i] - minV);
            minV = min(minV, prices[i]);
        }
        return res;
    }
};