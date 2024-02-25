class Solution {
public:
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    int oldColor;
    int newColor;
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != oldColor || image[sr][sc] == newColor) {
            return;
        }
        image[sr][sc] = newColor;
        for(int i = 0; i < 4; i++) dfs(image, sr+dx[i], sc+dy[i], newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        oldColor = image[sr][sc];
        dfs(image, sr, sc, newColor);
        return image;
    }
};

class Solution {
public:
    int oldColor;
    int a[4] = {1, -1, 0, 0};
    int b[4] = {0, 0, 1, -1};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        oldColor = image[sr][sc];
        dfs(image, sr, sc, newColor);
        return image;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor){
        if(sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] == newColor || image[sr][sc] != oldColor){
            return;
        }
        image[sr][sc] = newColor;
        for(int i = 0; i < 4; i++)
        {
            int nextR = sr + a[i];
            int nextC = sc + b[i];
            dfs(image, nextR, nextC, newColor);
        }
        return;
    }
};