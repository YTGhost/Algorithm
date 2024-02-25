class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int res = 0;
        sort(costs.begin(), costs.end());
        for(auto cost : costs) {
            if(coins < cost) break;
            else {
                coins -= cost;
                res++;
            }
        }
        return res;
    }
};