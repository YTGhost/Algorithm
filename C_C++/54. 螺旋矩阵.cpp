class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int x = 0, y = 0, m = matrix.size(), n = matrix[0].size();
        int cnt = m * n;
        vector<int> res;
        vector<int> dx = { 0, 1, 0, -1 }, dy = { 1, 0, -1, 0 };
        int idx = 0;
        while(cnt) {
            res.push_back(matrix[x][y]);
            matrix[x][y] = -101;
            int nx = x + dx[idx], ny = y + dy[idx];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n || matrix[nx][ny] == -101) {
                idx++;
                idx %= 4;
                nx = x + dx[idx], ny = y + dy[idx];
            }
            x = nx, y = ny;
            cnt--;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        vector<vector<bool>> st(m, vector<bool>(n, false));
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        int x = 0, y = 0, d = 0;
        for(int i = 0; i < m*n; i++)
        {
            res.emplace_back(matrix[x][y]);
            st[x][y] = true;
            int a = x + dx[d], b = y + dy[d];
            if(a < 0 || a >= m || b < 0 || b >= n || st[a][b]) {
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

// AcWing??
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(!matrix.size()) return ans;
        int sign = 1;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> check(m, vector<int>(n, 1));
        int nums = m*n;
        int count = 0;
        int i = 0, j = 0;
        
        while(count < nums)
        {
            ans.push_back(matrix[i][j]);
            check[i][j] = -1;
            if(++count == nums) break;
            if(sign == 1) j++;
            else if(sign == 2) i++;
            else if(sign == 3) j--;
            else i--;
            
            if(j == n){
                j--;
                i++;
                sign = 2;
            }else if(i == m){
                i--;
                j--;
                sign = 3;
            }else if(j == -1){
                j++;
                i--;
                sign = 4;
            }else if(i == -1){
                i++;
                j++;
                sign = 1;
            }

            if(check[i][j] == -1){
                if(sign == 1){
                    j--;
                    i++;
                    sign = 2;
                }else if(sign == 2){
                    i--;
                    j--;
                    sign = 3;
                }else if(sign == 3){
                    j++;
                    i--;
                    sign = 4;
                }else{
                    i++;
                    j++;
                    sign = 1;
                }
            }
        }
        return ans;
    }
};