class Solution {
public:
    bool check(string &s, int l, int r) {
        unordered_map<char, int> hash;
        for(int i = l; i <= r; i++) {
            hash[s[i] - 'a']++;
            if(hash.size() > 1) {
                return false;
            }
        }
        return true;
    }
    int maximumLength(string s) {
        int n = s.size();
        unordered_map<string, int> hash;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(check(s, i, j)) {
                    hash[s.substr(i, j - i + 1)]++;
                }
            }
        }
        int res = -1;
        for(auto &[str, cnt] : hash) {
            if(cnt >= 3 && (int)str.size() > res) {
                res = (int)str.size();
            }
        }
        return res;
    }
};