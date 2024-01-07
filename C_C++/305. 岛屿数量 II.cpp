class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> p(m * n);
        vector<int> res(positions.size());
        vector<vector<bool>> isLand(m, vector<bool>(n, false));
        int cnt = 0;
        for(int i = 0; i < m * n; i++) {
            p[i] = i;
        }
        function<int(int)> find = [&](int x) -> int {
            if(p[x] != x) p[x] = find(p[x]);
            return p[x];
        };
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        for(int i = 0; i < positions.size(); i++) {
            int r = positions[i][0], c = positions[i][1];
            if(isLand[r][c]) {
                res[i] = cnt;
                continue;
            }
            cnt++;
            isLand[r][c] = true;
            int index = r * n + c;
            for(int k = 0; k < 4; k++) {
                int nr = r + dx[k], nc = c + dy[k];
                int newIndex = nr * n + nc;
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && isLand[nr][nc] && find(index) != find(newIndex)) {
                    p[find(newIndex)] = find(index);
                    cnt--;
                }
            }
            res[i] = cnt;
        }
        return res;
    }
};