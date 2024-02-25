class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size();
        if(!n) return res;
        int m = matrix[0].size();
        vector<vector<bool>> st(n, vector<bool>(m, false));

        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        int x = 0, y = 0, d = 1;

        for(int i = 0; i < n*m; i++)
        {
            res.push_back(matrix[x][y]);
            st[x][y] = true;
            int a = x + dx[d], b = y + dy[d];
            if(a < 0 || a >= n || b < 0 || b >= m || st[a][b]){
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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size() == 0) return ans;
        int r = 0, c = 0, n = matrix.size(), m = matrix[0].size(), p = 0;
        vector<pair<int, int>> t = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int sum = n*m;
        int count = 0;
        vector<vector<int>> status(n, vector<int>(m, 0));
        
        while(count != sum)
        {
            if(p == 0 && (c == m-1 || status[r][c+1] == 1)) p = 1;
            else if(p == 1 && (r == n-1 || status[r+1][c] == 1)) p = 2;
            else if(p == 2 && (c == 0 || status[r][c-1] == 1)) p = 3;
            else if(p == 3 && (r == 0 || status[r-1][c] == 1)) p = 0; 
            ans.push_back(matrix[r][c]);
            status[r][c] = 1;
            count++;
            r += t[p].first;
            c += t[p].second;
        }
        return ans;
    }
};