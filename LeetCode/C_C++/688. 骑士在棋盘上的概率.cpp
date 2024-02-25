class Solution {
public:
    typedef pair<int, int> PII;
    double f[30][30][105];
    double knightProbability(int n, int k, int row, int column) {
        int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                f[i][j][0] = 1;
            }
        }
        for(int p = 1; p <= k; p++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    for(int q = 0; q < 8; q++) {
                        int nr = i + dx[q], nc = j + dy[q];
                        if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                        f[i][j][p] += f[nr][nc][p-1] / 8;
                    }
                }
            }
        }
        return f[row][column][k];
    }
};