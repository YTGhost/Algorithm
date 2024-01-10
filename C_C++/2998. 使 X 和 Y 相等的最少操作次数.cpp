class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(x <= y) return y - x;
        int res = x - y;
        queue<int> q;
        vector<int> vis(x + res + 1);
        int cnt = 0;
        q.push(x);
        auto add = [&](int v) {
            if(v < y) {
                res = min(res, cnt + y - v + 1);
            } else if(!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        };
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int a = q.front();
                q.pop();
                if(a == y) return min(res, cnt);
                if(a % 11 == 0) {
                    add(a / 11);
                }
                if(a % 5 == 0) {
                    add(a / 5);
                }
                add(a - 1);
                add(a + 1);
            }
            cnt++;
        }
        return min(res, cnt);
    }
};