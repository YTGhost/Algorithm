class Solution {
public:
    int bfs(string start) {
        unordered_map<string, int> d;
        queue<string> q;
        string end = "123450";
        d[start] = 0;
        q.push(start);
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        while(!q.empty()) {
            string t = q.front();
            int distance = d[t];
            q.pop();
            if(t == end) return d[t];
            int index = t.find('0');
            int a = index / 3, b = index % 3;
            for(int i = 0; i < 4; i++) {
                int newA = a + dx[i], newB = b + dy[i];
                if(newA >= 0 && newA < 2 && newB >= 0 && newB < 3) {
                    swap(t[index], t[3*newA + newB]);
                    if(!d.count(t)) {
                        d[t] = distance + 1;
                        q.push(t);
                    }
                    swap(t[index], t[3*newA + newB]);
                }
            }
        }
        return -1;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        string start;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 3; j++)
                start += to_string(board[i][j]);
        return bfs(start);
    }
};

class Solution {
public:
    int bfs(string start){
        unordered_map<string, int> d;
        queue<string> q;
        string end = "123450";
        int px[] = {1, 0, -1, 0}, py[] = {0, -1, 0, 1};
        q.push(start);
        d[start] = 0;
        while(!q.empty())
        {
            string t = q.front();
            int distance = d[t];
            q.pop();
            if(t == end) return d[t];
            int k = t.find('0');
            int a = k % 3, b = k / 3;
            for(int i = 0; i < 4; i++)
            {
                int newX = a + px[i];
                int newY = b + py[i];
                if(newX >= 0 && newX < 3 && newY >= 0 && newY < 2){
                    swap(t[k], t[newY*3 + newX]);
                    if(!d.count(t)){
                        d[t] = distance + 1;
                        q.push(t);
                    }
                    swap(t[k], t[newY*3 + newX]);
                }
            }
        }
        return -1;
}
    int slidingPuzzle(vector<vector<int>>& board) {
        string start;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 3; j++)
                start += to_string(board[i][j]);
        return bfs(start);
    }
};