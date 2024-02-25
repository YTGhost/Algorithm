class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int m = image.size(), n = image[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        vector<vector<int>> count(m, vector<int>(n, 0));
        int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
        int ddx[4] = {-1, 0, 1, 0}, ddy[4] = {0, 1, 0, -1};
        function<void(int, int)> handle = [&](int i, int j) {
            int sum = image[i][j];
            for(int k = 0; k < 8; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                for(int l = 0; l < 4; l++) {
                    int nnx = nx + ddx[l], nny = ny + ddy[l];
                    if(nnx < i - 1 || nnx > i + 1 || nny < j - 1 || nny > j + 1) continue;
                    if(abs(image[nx][ny] - image[nnx][nny]) > threshold) return;
                    
                }
                sum += image[nx][ny];
            }
            int average = sum / 9;
            res[i][j] += average;
            count[i][j]++;
            for(int k = 0; k < 8; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                res[nx][ny] += average;
                count[nx][ny]++;
            }
        };
        for(int i = 1; i < m - 1; i++) {
            for(int j = 1; j < n - 1; j++) {
                handle(i, j);
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(count[i][j] == 0) res[i][j] = image[i][j];
                else res[i][j] = res[i][j] / count[i][j];
            }
        }
        return res;
    }
};