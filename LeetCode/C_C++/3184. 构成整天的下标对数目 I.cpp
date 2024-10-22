class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int n = hours.size(), res = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                res += (hours[i] + hours[j]) % 24 == 0 ? 1 : 0;
            }
        }
        return res;
    }
};