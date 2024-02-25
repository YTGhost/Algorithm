const int N = 55;

class Solution {
public:
    int f[2 * N * N][N][N];
    vector<vector<int>> g;
    int n;
    int catMouseGame(vector<vector<int>>& graph) {
        g = graph;
        n = g.size();
        for(int k = 0; k < 2 * n * n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    f[k][i][j] = -1;
                }
            }
        }
        return dfs(0, 1, 2);
    }
    int dfs(int k, int a, int b) {
        int res = f[k][a][b];
        if(a == 0) res = 1;
        else if(a == b) res = 2;
        else if(k >= 2 * n * n) res = 0;
        else if(res == -1) {
            if(k % 2 == 0) { // mouse
                bool win = false, draw = false;
                for(auto ne : g[a]) {
                    int t = dfs(k + 1, ne, b);
                    if(t == 1) win = true;
                    else if(t == 0) draw = true;
                    if(win) break;
                }
                if(win) res = 1;
                else if(draw) res = 0;
                else res = 2;
            } else { // cat
                bool win = false, draw = false;
                for(auto ne : g[b]) {
                    if(ne == 0) continue;
                    int t = dfs(k + 1, a, ne);
                    if(t == 2) win = true;
                    else if(t == 0) draw = true;
                    if(win) break;
                }
                if(win) res = 2;
                else if(draw) res = 0;
                else res = 1;
            }
        }
        f[k][a][b] = res;
        return res;
    }
};