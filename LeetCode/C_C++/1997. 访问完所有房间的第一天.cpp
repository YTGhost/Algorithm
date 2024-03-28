class Solution {
public:
    const int MOD = 1e9 + 7;
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n = nextVisit.size();
        vector<long> s(n);
        for(int i = 0; i < n - 1; i++) {
            int j = nextVisit[i];
            s[i + 1] = (s[i] * 2 - s[j] + 2 + MOD) % MOD;
        }
        return s[n - 1];
    }
};