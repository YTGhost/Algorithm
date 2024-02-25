class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<int> idxs(n);
        iota(idxs.begin(), idxs.end(), 0);
        ranges::sort(idxs, [&](int i, int j) {
            return aliceValues[i] + bobValues[i] > aliceValues[j] + bobValues[j];
        });
        int diff = 0;
        for(int i = 0; i < n; i++) {
            diff += i % 2 == 0 ? aliceValues[idxs[i]] : -bobValues[idxs[i]];
        }
        if(diff > 0) return 1;
        else if(diff < 0) return -1;
        return 0;
    }
};