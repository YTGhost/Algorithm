// 空间优化
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> w(n, vector<int>(n, INT_MAX / 2));
        for(auto &e : edges) {
            int x = e[0], y = e[1], wt = e[2];
            w[x][y] = w[y][x] = wt;
        }

        auto f = move(w);
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }
        int res = 0;
        int min_cnt = n;
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(i != j && f[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }
            if(cnt <= min_cnt) {
                min_cnt = cnt;
                res = i;
            }
        }
        return res;
    }
};

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> w(n, vector<int>(n, INT_MAX / 2));
        for(auto &e : edges) {
            int x = e[0], y = e[1], wt = e[2];
            w[x][y] = w[y][x] = wt;
        }

        vector<vector<vector<int>>> f(n + 1, vector<vector<int>>(n, vector<int>(n)));
        f[0] = w;
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    f[k + 1][i][j] = min(f[k][i][j], f[k][i][k] + f[k][k][j]);
                }
            }
        }
        int res = 0;
        int min_cnt = n;
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(i != j && f[n][i][j] <= distanceThreshold) {
                    cnt++;
                }
            }
            if(cnt <= min_cnt) {
                min_cnt = cnt;
                res = i;
            }
        }
        return res;
    }
};