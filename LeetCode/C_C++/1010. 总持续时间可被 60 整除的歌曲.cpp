class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> cnt(60);
        for(auto t : time) {
            cnt[t % 60]++;
        }
        long long res = 0;
        res += (long long)cnt[0] * (cnt[0] - 1) / 2;
        res += (long long)cnt[30] * (cnt[30] - 1) / 2;
        for(int i = 1; i < 30; i++) {
            res += cnt[i] * cnt[60 - i];
        }
        return res;
    }
};