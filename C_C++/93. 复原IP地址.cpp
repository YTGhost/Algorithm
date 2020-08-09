class Solution {
public:
    vector<string> ans;
    void dfs(string &s, int u, int k, string path) {
        if(u == s.size()) {
            if(k == 4) {
                path.pop_back();
                ans.push_back(path);
            }
            return;
        }
        if(k == 4) return;

        for(int i = u, t = 0; i < s.size(); i++)
        {
            if(i > u && s[u] == '0') break;
            t = t * 10 + s[i] - '0';
            if(t <= 255) dfs(s, i+1, k+1, path + to_string(t) + ".");
            else break;
        }
    }

    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 0, "");
        return ans;
    }
};