class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for(auto operation : operations) {
            int x = operation[0], y = operation[1];
            int half = gem[x] / 2;
            gem[x] -= half;
            gem[y] += half;
        }
        int maxValue = INT_MIN, minValue = INT_MAX;
        for(auto t : gem) {
            maxValue = max(maxValue, t);
            minValue = min(minValue, t);
        }
        return maxValue - minValue;
    }
};