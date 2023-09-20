class Solution {
public:
    int minCount(vector<int>& coins) {
        int res = 0;
        for(auto coin : coins) {
            int t = coin / 2;
            coin %= 2;
            res += t + coin;
        }
        return res;
    }
};