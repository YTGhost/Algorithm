class Solution {
public:
    map<vector<int>, int> memo;
    int dfs(vector<int>& price, vector<vector<int>>& filteredSpecial, vector<int> curNeeds, int n) {
        if (!memo.count(curNeeds)) {
            int minPrice = 0;
            for (int i = 0; i < n; i++) {
                minPrice += price[i] * curNeeds[i];
            }
            for (auto &sp : filteredSpecial) {
                vector<int> nextNeeds;
                for (int i = 0; i < n; i++) {
                    if (sp[i] > curNeeds[i]) {
                        break;
                    }
                    nextNeeds.push_back(curNeeds[i] - sp[i]);
                }
                if (nextNeeds.size() == n) {
                    minPrice = min(minPrice, dfs(price, filteredSpecial, nextNeeds, n) + sp[n]);
                }
            }
            memo[curNeeds] = minPrice;
        }
        return memo[curNeeds];
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        vector<vector<int>> filteredSpecial;
        for (auto &sp : special) {
            int totalCnt = 0, totalPrice = 0;
            for (int i = 0; i < n; i++) {
                totalCnt += sp[i];
                totalPrice += price[i] * sp[i];
            }
            if (totalCnt > 0 && totalPrice > sp[n]) {
                filteredSpecial.push_back(sp);
            }
        }
        return dfs(price, filteredSpecial, needs, n);
    }
};