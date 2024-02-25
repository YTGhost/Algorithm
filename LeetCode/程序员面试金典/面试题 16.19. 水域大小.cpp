class Solution {
public:
    vector<int> res;
    vector<int> dx{-1, -1, 0, 1, 1, 1, 0, -1};
    vector<int> dy{0, 1, 1, 1, 0, -1, -1, -1};
    vector<int> pondSizes(vector<vector<int>>& land) {
        int n = land.size(), m = land[0].size();
        function<int(int, int)> dfs = [&](int x, int y) -> int {
            if(x < 0 || x >= n || y < 0 || y >= m) {
                return 0;
            }
            if(land[x][y] != 0) {
                return 0;
            }
            land[x][y] = -1;
            int sum = 1;
            for(int i = 0; i < 8; i++) {
                sum += dfs(x + dx[i], y + dy[i]);
            }
            return sum;
        };
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(land[i][j] == 0) {
                    res.push_back(dfs(i, j));
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};