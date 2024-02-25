class Solution {
public:
    string num;
    int n;
    vector<vector<int>> list;
    bool isAdditiveNumber(string _num) {
        num = _num;
        n = _num.size();
        return dfs(0);
    }
    bool dfs(int u) {
        int m = list.size();
        if(u == n) return m >= 3;
        int max = num[u] == '0' ? u + 1 : n;
        vector<int> cur;
        for(int i = u; i < max; i++) {
            cur.insert(cur.begin(), num[i] - '0');
            if(m < 2 || check(list[m - 2], list[m - 1], cur)) {
                list.push_back(cur);
                if(dfs(i + 1)) return true;
                list.pop_back();
            }
        }
        return false;
    }
    bool check(vector<int>& a, vector<int>& b, vector<int>& c) {
        vector<int> res;
        int t = 0;
        for(int i = 0; i < a.size() || i < b.size(); i++) {
            if(i < a.size()) t += a[i];
            if(i < b.size()) t += b[i];
            res.push_back(t % 10);
            t /= 10;
        }
        if(t) res.push_back(1);
        bool ok = c.size() == res.size();
        for(int i = 0; i < c.size() && ok; i++) {
            if(c[i] != res[i]) ok = false;
        }
        return ok;
    }
};