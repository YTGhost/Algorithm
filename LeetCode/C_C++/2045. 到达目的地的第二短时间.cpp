class Solution {
public:
    typedef pair<int, int> PII;
    const static int inf = 0x3f3f3f3f, N = 10010, M = 4 * N;
    int e[M], ne[M], h[N], dist1[N], dist2[N], idx = 0;
    void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        memset(dist1, inf, sizeof dist1);
        memset(dist2, inf, sizeof dist2);
        memset(h, -1, sizeof h);
        for(auto edge : edges) {
            add(edge[0], edge[1]);
            add(edge[1], edge[0]);
        }
        priority_queue<PII, vector<PII>, greater<PII>> q;
        q.push({0, 1});
        dist1[1] = 0;
        while(q.size()) {
            auto item = q.top();
            q.pop();
            for(int i = h[item.second]; ~i; i = ne[i]) {
                int val = e[i];
                int a = item.first / change, b = item.first % change;
                int wait = a % 2 == 0 ? 0 : change - b;
                int dist = item.first + time + wait;
                if(dist < dist1[val]) {
                    dist2[val] = dist1[val];
                    dist1[val] = dist;
                    q.push({dist2[val], val});
                    q.push({dist1[val], val});
                } else if(dist1[val] < dist && dist < dist2[val]) {
                    dist2[val] = dist;
                    q.push({dist2[val], val});
                }
            }
        }
        return dist2[n];
    }
};