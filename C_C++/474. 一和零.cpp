class Solution {
public:
    int f[110][110];
    pair<int, int> get(string& str) {
        int m = 0, n = 0;
        for(auto c : str)
            c == '0' ? m++ : n++;
        return make_pair(m, n);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        for(int i = 0; i < len; i++)
        {
            auto p = get(strs[i]);
            for(int j = m; j >= p.first; j--)
                for(int k = n; k >= p.second; k--)
                    f[j][k] = max(f[j][k], f[j-p.first][k-p.second] + 1);
        }
        return f[m][n];
    }
};