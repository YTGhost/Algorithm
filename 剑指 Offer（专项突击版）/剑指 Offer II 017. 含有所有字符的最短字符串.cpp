class Solution {
public:
    unordered_map<char, int> cnt, hash;
    bool check() {
        for(auto &s : hash) {
            if(cnt[s.first] < s.second) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        for(auto &c : t) {
            hash[c]++;
        }
        int l = 0, r = -1, n = s.length(), len = INT_MAX, resL = -1;
        while(r < n) {
            cnt[s[++r]]++;
            while(check() && l <= r) {
                if(r - l + 1 < len) {
                    len = r - l + 1;
                    resL = l;
                }
                if(hash[s[l]]) {
                    cnt[s[l]]--;
                }
                l++;
            }
        }
        return resL == -1 ? "" : s.substr(resL, len);
    }
};