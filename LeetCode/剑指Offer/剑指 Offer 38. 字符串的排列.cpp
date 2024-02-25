class Solution {
public:
    vector<string> res;
    void dfs(string& str, int u, string cur, vector<int>& visited) {
        int n = str.size();
        if(u == n) {
            res.push_back(cur);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(i > 0 && !visited[i-1] && str[i] == str[i - 1]) continue;
            if(!visited[i]) {
                visited[i] = 1;
                dfs(str, u + 1, cur + str[i], visited);
                visited[i] = 0;
            }
        }
    }
    vector<string> permutation(string s) {
        int n = s.size();
        vector<int> visited(n);
        sort(s.begin(), s.end());
        dfs(s, 0, "", visited);
        return res;
    }
};

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