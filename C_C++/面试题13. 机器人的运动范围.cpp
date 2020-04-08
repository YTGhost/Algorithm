class Solution {
public:
    int grid[100][100];
    int dfs(int x, int y, int m, int n, int k){
        if(x == m || y == n || x%10 + x/10 + y%10 + y/10 > k || grid[x][y] == 1)
            return 0;
        grid[x][y] = 1;
        return 1 + dfs(x+1, y, m, n, k) + dfs(x, y+1, m, n, k);
    }

    int movingCount(int m, int n, int k) {
        return dfs(0, 0, m, n, k);
    }
};