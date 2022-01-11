class Solution {
public:
    int MAX = 1e5, EDGE = 1e6;
    long long BASE = 13331;
    unordered_set<long long> set;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        for(auto& p : blocked) {
            set.insert(p[0] * BASE + p[1]);
        }
        int n = blocked.size();
        MAX = n * (n - 1) / 2;
        return check(source, target) && check(target, source);
    }
    bool check(vector<int>& a, vector<int>& b) {
        unordered_set<long long> visit;
        queue<pair<int, int>> q;
        q.push({a[0], a[1]});
        visit.insert(a[0] * BASE + a[1]);
        while(q.size() && visit.size() <= MAX) {
            auto t = q.front();
            q.pop();
            int x = t.first, y = t.second;
            if(x == b[0] && y == b[1]) return true;
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || nx >= EDGE || ny < 0 || ny >= EDGE) continue;
                if(set.count(nx * BASE + ny)) continue;
                if(visit.count(nx * BASE + ny)) continue;
                q.push({nx, ny});
                visit.insert(nx * BASE + ny);
            }
        }
        return visit.size() > MAX;
    }
};