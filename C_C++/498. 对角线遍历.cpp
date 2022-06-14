class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int cnt = n * m;
        bool flag = true;
        vector<int> res(cnt);
        int x = 0, y = 0;
        for(int i = 0; i < cnt; i++) {
            res[i] = mat[x][y];
            int nx, ny;
            if(flag) nx = x - 1, ny = y + 1;
            else nx = x + 1, ny = y - 1;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                if(flag) {
                    nx = x, ny = y + 1;
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                        nx = x + 1, ny = y;
                    }
                } else {
                    nx = x + 1, ny = y;
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                        nx = x, ny = y + 1;
                    }
                }
                flag = !flag;
            }
            x = nx, y = ny;
        }
        return res;
    }
};