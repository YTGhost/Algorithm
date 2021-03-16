class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        int x = 0, y = 0, d = 0;
        for(int i = 1; i <= n*n; i++)
        {
            res[x][y] = i;
            int a = x + dx[d], b = y + dy[d];
            if(a < 0 || a >= n || b < 0 || b >= n || res[a][b]) {
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
            }
            x = a, y = b;
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        for(int x = 0, y = 0, k = 1, d = 0; k <= n*n; k++)
        {
            res[x][y] = k;
            int a = x + dx[d], b = y + dy[d];
            if(a >= n || a < 0 || b >= n || b < 0 || res[a][b])
            {
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
            }
            x = a, y = b;
        }
        return res;
    }
};
