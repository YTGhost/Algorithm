class Solution {
public:
    typedef pair<int, int> PII;
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        priority_queue<PII> q;
        if(a > 0) q.push({a, 'a'});
        if(b > 0) q.push({b, 'b'});
        if(c > 0) q.push({c, 'c'});
        while(!q.empty()) {
            auto cur = q.top();
            q.pop();
            int n = res.length();
            if(n >= 2 && res[n - 1] == cur.second && res[n - 2] == cur.second) {
                if(q.empty()) break;
                auto next = q.top();
                q.pop();
                res += next.second;
                if(--next.first) q.push(next);
                q.push(cur);
            } else {
                res += cur.second;
                if(--cur.first) q.push(cur);
            }
        }
        return res;
    }
};