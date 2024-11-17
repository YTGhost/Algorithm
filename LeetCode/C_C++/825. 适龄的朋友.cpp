class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size(), res = 0;
        vector<int> cnt(121);
        for (auto age : ages) {
            cnt[age]++;
        }
        int window = 0, y = 1;
        for (int x = 1; x <= 120; x++) {
            window += cnt[x];
            if (2 * y <= x + 14) {
                window -= cnt[y];
                y++;
            }
            if (window > 0) {
                res += cnt[x] * window - cnt[x];
            }
        }
        return res;
    }
};

class Solution {
public:
    bool check(int x, int y) {
        if(y <= 0.5 * x + 7) return false;
        if(y > x) return false;
        if(y > 100 && x < 100) return false;
        return true;
    }
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int res = 0, n = ages.size();
        for(int k = 0, i = 0, j = 0; k < n; k++) {
            while(i < k && !check(ages[i], ages[k])) i++;
            if(j < k) j = k;
            while(j < n && check(ages[j], ages[k])) j++;
            if(j > i) res += j - i - 1;
        }
        return res;
    }
};