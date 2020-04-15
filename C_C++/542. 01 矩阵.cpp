class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<vector<int>> q;
        int m = matrix.size();
        int n = matrix[0].size();
        int p1[4] = {1, 0, -1, 0};
        int p2[4] = {0, -1, 0, 1};

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == 0){
                    vector<int> t = {i, j};
                    q.push(t);
                }else{
                    matrix[i][j] = -1;
                }
            }

        while(!q.empty())
        {
            vector<int> point = q.front();
            q.pop();
            int x = point[0], y = point[1];
            for(int i = 0; i < 4; i++)
            {
                int newX = x + p1[i];
                int newY = y + p2[i];
                if(newX >= 0 && newX < m && newY >= 0 && newY < n && matrix[newX][newY] == -1)
                {
                    matrix[newX][newY] = matrix[x][y] + 1;
                    vector<int> t = {newX, newY};
                    q.push(t);
                }
            }
        }
        return matrix;
    }
};