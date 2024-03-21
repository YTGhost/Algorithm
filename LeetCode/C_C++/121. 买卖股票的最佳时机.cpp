class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = INT_MAX, res = 0;
        for(auto price : prices) {
            if (price < minVal) {
                minVal = price;
            } else {
                res = max(res, price - minVal);
            }
        }
        return res;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cost = INT_MAX, profit = 0;
        for(int i = 0; i < n; i++) {
            cost = min(cost, prices[i]);
            profit = max(profit, prices[i] - cost);
        }
        return profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            minPrice = min(prices[i], minPrice);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};