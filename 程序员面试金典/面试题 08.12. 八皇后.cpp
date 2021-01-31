class Solution {
public:
    vector<vector<string>> a;
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> g(n, vector<char>(n, '.'));
        vector<bool> col(n, false);
        vector<bool> dg(2*n, false);
        vector<bool> udg(2*n, false);
        dfs(0, n, g, col, dg, udg);
        return a;
    }

    void dfs(int u, int n, vector<vector<char>> g, vector<bool> col, vector<bool> dg, vector<bool> udg){
        if(u == n){
            vector<string> t;
            for(int i = 0; i < n; i++)
            {
                string str;
                str.insert(str.begin(), g[i].begin(), g[i].end());
                t.push_back(str);
            }
            a.push_back(t);
            return;
        }

        for(int i = 0; i < n; i++)
        {
            if(!col[i] && !dg[u + i] && !udg[n + i - u]){
                g[u][i] = 'Q';
                col[i] = dg[u + i] = udg[n + i - u] = true;
                dfs(u + 1, n, g, col, dg, udg);
                col[i] = dg[u + i] = udg[n + i - u] = false;
                g[u][i] = '.';
            }
        }
    }
};