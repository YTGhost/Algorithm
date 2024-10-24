class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {

        }
        int l = 0, r = l + 1;
        while (l < n && r < n) {
            if (skills[l] > skills[r]) {
                cnt[l]++;
                if (cnt[l] == k) return l;
                r++;
            } else {
                cnt[l] = 0;
                cnt[r]++;
                if (cnt[r] == k) return r;
                l = r;
                r = l + 1;
            }
        }
        return l;
    }
};