class Solution {
public:
    string res = "";
    void dfs(int idx, int k, string& s) {
        int cnt = 0;
        int n = s.size();
        for(int i = idx; i < n; i++) {
            if(s[i] == '1') {
                cnt++;
                if(cnt == k) {
                    string t = s.substr(idx, i - idx + 1);
                    if(res == "") {
                        res = t;
                    } else if(t.size() == res.size() && t < res) {
                        res = t;
                    } else if(t.size() < res.size()) {
                        res = t;
                    }
                    break;
                }
            }
        }
    }
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                dfs(i, k, s);
            }
        }
        return res;
    }
};