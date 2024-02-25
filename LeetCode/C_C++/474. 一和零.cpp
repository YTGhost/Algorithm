class Solution {
public:
    vector<int> getSum(string t) {
        vector<int> sum(2);
        for(auto c : t) sum[c - '0']++;
        return sum;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<vector<int>>> f(len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        for(int i = 1; i <= len; i++) {
            vector<int>&& t = getSum(strs[i-1]);
            int a = t[0], b = t[1];
            for(int j = 0; j <= m; j++) {
                for(int k = 0; k <= n; k++) {
                    f[i][j][k] = f[i-1][j][k];
                    if(j >= a && k >= b) {
                        f[i][j][k] = max(f[i][j][k], f[i-1][j-a][k-b] + 1);
                    }
                }
            }
        }
        return f[len][m][n];
    }
};

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