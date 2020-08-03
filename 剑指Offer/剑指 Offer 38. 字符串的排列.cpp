class Solution {
public:
    vector<string> res;
    string path = "11111111";

    void dfs(string& s, int u, int start, int state) {
        if(u == s.length())
        {
            res.push_back(path.substr(0, s.length()));
            return;
        }
        if(!u || s[u] != s[u-1]) start = 0;
        for(int i = start; i < s.length(); i++)
            if(!(state >> i & 1))
            {
                path[i] = s[u];
                dfs(s, u+1, i+1, state + (1 << i));
            }
    }

    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        dfs(s, 0, 0, 0);
        return res;
    }
};