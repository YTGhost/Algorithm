class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        vector<vector<int>> hash(26);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt++;
            if(i + 1 == n || s[i] != s[i + 1]) {
                hash[s[i] - 'a'].push_back(cnt);
                cnt = 0;
            }
        }
        int res = 0;
        for(auto &arr : hash) {
            if(arr.empty()) continue;
            sort(arr.rbegin(), arr.rend());
            arr.push_back(0);
            arr.push_back(0);
            res = max({res, arr[0] - 2, min(arr[0] - 1, arr[1]), arr[2]});
        }
        return res == 0 ? -1 : res;
    }
};

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