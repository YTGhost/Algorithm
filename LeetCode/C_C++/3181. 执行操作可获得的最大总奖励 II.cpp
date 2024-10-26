class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        rewardValues.erase(unique(rewardValues.begin(), rewardValues.end()), rewardValues.end());
        bitset<100000> f{1};
        for (int val : rewardValues) {
            int shift = f.size() - val;
            f |= f << shift >> shift << val;
        }
        int res = 0;
        for (int i = rewardValues.back() * 2 - 1; i >= 0; i--) {
            if (f.test(i)) {
                res = i;
                break;
            }
        }
        return res;
    }
};