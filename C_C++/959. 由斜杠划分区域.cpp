class Solution {
public:
    int p[3610];
    int find(int x) {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void merge(int x, int y) {
        p[find(x)] = find(y);
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        for(int i = 0; i < n*n*4; i++) p[i] = i;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                int index = i * n + j;
                // 最后一行就没有bottom了
                if(i < n-1) {
                    int bottom = index + n;
                    merge(index * 4 + 2, bottom * 4);
                }
                // 最后一列就没有right了
                if(j < n-1) {
                    int right = index + 1;
                    merge(index * 4 + 1, right * 4 + 3);
                }
                if(grid[i][j] == '/') {
                    merge(index * 4 + 1, index * 4 + 2);
                    merge(index * 4, index * 4 + 3);
                } else if(grid[i][j] == '\\') {
                    merge(index * 4, index * 4 + 1);
                    merge(index * 4 + 2, index * 4 + 3);
                } else {
                    merge(index * 4, index * 4 + 1);
                    merge(index * 4 + 1, index * 4 + 2);
                    merge(index * 4 + 2, index * 4 + 3);  
                }
            }
        int res = 0;
        for(int i = 0; i < n * n * 4; i++)
            if(p[i] == i) res++;
        return res;
    }
};