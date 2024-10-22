class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        int n = hours.size();
        vector<int> cnt(24);
        long long res = 0;
        for (auto hour : hours) {
            res += cnt[(24 - hour % 24) % 24];
            cnt[hour % 24]++;
        }
        return res;
    }
};